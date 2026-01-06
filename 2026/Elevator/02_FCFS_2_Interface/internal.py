import json
import time
import os

class Elevator:
    def __init__(self):
        self.current_floor = 0
        self.requests_file = os.path.join(os.path.dirname(__file__), "elevator_requests.json")
        self._init_requests_file()
    
    def _init_requests_file(self):
        if not os.path.exists(self.requests_file):
            with open(self.requests_file, 'w') as f:
                json.dump([], f)
    
    def _get_requests(self):
        with open(self.requests_file, 'r') as f:
            return json.load(f)
    
    def _clear_request(self, floor):
        requests = self._get_requests()
        if floor in requests:
            requests.remove(floor)
        with open(self.requests_file, 'w') as f:
            json.dump(requests, f)
    
    def move_to(self, floor):
        while self.current_floor != floor:
            if self.current_floor < floor:
                self.current_floor += 1
            else:
                self.current_floor -= 1
            time.sleep(1)
            print(f"[Elevator Moving] Current Floor: {self.current_floor}")
    
    def run(self):
        print("[Internal System] Elevator started...")
        while True:
            requests = self._get_requests()
            if requests:
                pickup = requests[0]
                print(f"\n--- Pickup request at Floor: {pickup} ---")
                self.move_to(pickup)
                self._clear_request(pickup)
                
                dest = int(input("Lift reached. Enter destination floor: "))
                print(f"--- Going to Floor: {dest} ---")
                self.move_to(dest)
                print(f"[Arrived] Destination Floor: {dest}\n")
            else:
                time.sleep(1)

if __name__ == "__main__":
    elevator = Elevator()
    elevator.run()