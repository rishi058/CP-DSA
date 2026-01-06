import json
import time
import os
from enum import Enum

def log_to_file(from_floor, to_floor):
    elevator_log_path = os.path.join(os.path.dirname(__file__), "elevator_log.txt")
    with open(elevator_log_path, "a") as log_file:
        log_file.write(f"Elevator({from_floor}, {to_floor})\n")

class Direction(Enum):
    UP = "UP"
    DOWN = "DOWN"
    IDLE = "IDLE"

class Elevator:
    def __init__(self, total_floors=10):
        self.total_floors = total_floors
        self.current_floor = 0
        self.prev_floor = 0
        self.direction = Direction.IDLE
        self.destinations = []  # List of destination floors
        self.requests_file = os.path.join(os.path.dirname(__file__), "elevator_requests.json")
        self._init_requests_file()
    
    def _init_requests_file(self):
        if not os.path.exists(self.requests_file):
            with open(self.requests_file, 'w') as f:
                json.dump([], f)
    
    def _get_requests(self):
        with open(self.requests_file, 'r') as f:
            return json.load(f)
    
    def _save_requests(self, requests):
        with open(self.requests_file, 'w') as f:
            json.dump(requests, f)
    
    def _clear_request(self, floor, direction):
        requests = self._get_requests()
        req_to_remove = {"floor": floor, "direction": direction}
        if req_to_remove in requests:
            requests.remove(req_to_remove)
            self._save_requests(requests)
    
    def _get_status(self):
        """Return current elevator status"""
        return {
            "current_floor": self.current_floor,
            "prev_floor": self.prev_floor,
            "direction": self.direction.value,
            "destinations": self.destinations.copy()
        }
    
    def _insert_destination_scan(self, floor):
        """Insert destination using SCAN algorithm logic"""
        if floor in self.destinations:
            return  # Already in list
        
        if not self.destinations:
            self.destinations.append(floor)
            return
        
        # SCAN insertion: insert in correct position based on current direction
        if self.direction == Direction.UP:
            # For UP: floors above current go in ascending order
            # Floors below current will be visited on the way back (descending)
            above = [f for f in self.destinations if f > self.current_floor]
            below = [f for f in self.destinations if f <= self.current_floor]
            
            if floor > self.current_floor:
                above.append(floor)
                above.sort()
            else:
                below.append(floor)
                below.sort(reverse=True)
            
            self.destinations = above + below
        
        elif self.direction == Direction.DOWN:
            # For DOWN: floors below current go in descending order
            # Floors above current will be visited on the way back (ascending)
            below = [f for f in self.destinations if f < self.current_floor]
            above = [f for f in self.destinations if f >= self.current_floor]
            
            if floor < self.current_floor:
                below.append(floor)
                below.sort(reverse=True)
            else:
                above.append(floor)
                above.sort()
            
            self.destinations = below + above
        
        else:  # IDLE
            self.destinations.append(floor)
    
    def _process_external_requests(self):
        """Process external requests and add to destinations using SCAN"""
        requests = self._get_requests()
        
        for req in requests:
            floor = req["floor"]
            req_dir = req["direction"]
            
            # Determine if this request should be picked up based on SCAN
            should_add = False
            
            if self.direction == Direction.IDLE:
                should_add = True
                # Set direction based on first request
                if floor > self.current_floor:
                    self.direction = Direction.UP
                elif floor < self.current_floor:
                    self.direction = Direction.DOWN
            
            elif self.direction == Direction.UP:
                # Pick up if: floor is above AND person wants to go UP
                # OR we'll get them on the way back
                if floor >= self.current_floor and req_dir == 'U':
                    should_add = True
                elif floor < self.current_floor or req_dir == 'D':
                    # Will be picked on return journey
                    should_add = True
            
            elif self.direction == Direction.DOWN:
                # Pick up if: floor is below AND person wants to go DOWN
                # OR we'll get them on the way back
                if floor <= self.current_floor and req_dir == 'D':
                    should_add = True
                elif floor > self.current_floor or req_dir == 'U':
                    # Will be picked on return journey
                    should_add = True
            
            if should_add and floor not in self.destinations:
                self._insert_destination_scan(floor)
    
    def _move_one_floor(self, target_floor):
        """Move one floor towards target, handling in-between state"""
        if self.current_floor == target_floor:
            return
        
        self.prev_floor = self.current_floor
        
        # Determine direction
        if target_floor > self.current_floor:
            self.direction = Direction.UP
            next_floor = self.current_floor + 1
        else:
            self.direction = Direction.DOWN
            next_floor = self.current_floor - 1
        
        # In-between state (2 seconds)
        self.current_floor = -1  # In between floors
        print(f"[Elevator] In transit... (between Floor {self.prev_floor} and {next_floor})")
        time.sleep(2)
        
        # Arrive at next floor
        self.current_floor = next_floor
        print(f"[Elevator] Current Floor: {self.current_floor} | Direction: {self.direction.value}")
        time.sleep(0.5)  # Brief pause at floor
    
    def move_to(self, floor):
        """Move to a specific floor"""
        start_floor = self.current_floor if self.current_floor != -1 else self.prev_floor
        
        while self.current_floor != floor:
            # Check for new requests and potentially update destinations
            self._process_external_requests()
            self._move_one_floor(floor)
        
        log_to_file(start_floor, floor)
    
    def _update_direction_if_needed(self):
        """Update direction based on remaining destinations"""
        if not self.destinations:
            self.direction = Direction.IDLE
            return
        
        next_dest = self.destinations[0]
        if next_dest > self.current_floor:
            self.direction = Direction.UP
        elif next_dest < self.current_floor:
            self.direction = Direction.DOWN
    
    def run(self):
        print("[System] Elevator started (SCAN Algorithm)...")
        print(f"[System] Total floors: 0 to {self.total_floors - 1}")
        print(f"[System] Starting at Floor: {self.current_floor}\n")
        
        while True:
            # Process any pending external requests
            self._process_external_requests()
            
            if self.destinations:
                # Get next destination
                next_stop = self.destinations[0]
                
                # Get the request info for this floor
                requests = self._get_requests()
                req_direction = None
                for req in requests:
                    if req["floor"] == next_stop:
                        req_direction = req["direction"]
                        break
                
                status = self._get_status()
                print(f"\n[Status] Floor: {status['current_floor']} | Dir: {status['direction']} | Queue: {status['destinations']}")
                print(f"--- Pickup request at Floor: {next_stop} ---")
                
                # Move to pickup
                self.move_to(next_stop)
                
                # Remove from destinations and clear request
                self.destinations.pop(0)
                if req_direction:
                    self._clear_request(next_stop, req_direction)
                
                # Get destination from passenger
                while True:
                    try:
                        dest_input = input(f"Lift reached Floor {next_stop}. Enter destination floor (0-{self.total_floors-1}): ")
                        dest = int(dest_input)
                        if 0 <= dest < self.total_floors:
                            break
                        print(f"[Error] Floor must be between 0 and {self.total_floors - 1}")
                    except ValueError:
                        print("[Error] Invalid input. Enter a number.")
                
                # Add destination using SCAN
                self._insert_destination_scan(dest)
                print(f"--- Added Floor {dest} to destinations ---")
                print(f"[Updated Queue] {self.destinations}")
                
                # Update direction if needed
                self._update_direction_if_needed()
                
                # If the next destination in queue is the one we just added, move there
                if self.destinations and self.destinations[0] == dest:
                    print(f"--- Going to Floor: {dest} ---")
                    self.move_to(dest)
                    self.destinations.pop(0)
                    print(f"[Arrived] Destination Floor: {dest}\n")
                    self._update_direction_if_needed()
            else:
                self.direction = Direction.IDLE
                time.sleep(1)

if __name__ == "__main__":
    elevator = Elevator(total_floors=10)
    elevator.run()