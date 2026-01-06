import json
import os

class ExternalInterface:
    def __init__(self, total_floors=10):
        self.total_floors = total_floors  # 0 to total_floors-1
        self.requests_file = os.path.join(os.path.dirname(__file__), "elevator_requests.json")
        self._init_requests_file()
    
    def _init_requests_file(self):
        if not os.path.exists(self.requests_file):
            with open(self.requests_file, 'w') as f:
                json.dump([], f)
    
    def _parse_request(self, request_str):
        """Parse request like '8U' or '5D' into (floor, direction)"""
        request_str = request_str.strip().upper()
        if len(request_str) < 2:
            return None, None
        
        direction = request_str[-1]
        if direction not in ('U', 'D'):
            return None, None
        
        try:
            floor = int(request_str[:-1])
        except ValueError:
            return None, None
        
        return floor, direction
    
    def _validate_request(self, floor, direction):
        """Validate the request based on floor boundaries"""
        if floor < 0 or floor >= self.total_floors:
            print(f"[Error] Floor must be between 0 and {self.total_floors - 1}")
            return False
        
        # Can't go down from ground floor
        if floor == 0 and direction == 'D':
            print("[Error] Cannot request DOWN from ground floor (0)")
            return False
        
        # Can't go up from top floor
        if floor == self.total_floors - 1 and direction == 'U':
            print(f"[Error] Cannot request UP from top floor ({self.total_floors - 1})")
            return False
        
        return True
    
    def call_elevator(self, request_str):
        floor, direction = self._parse_request(request_str)
        
        if floor is None or direction is None:
            print("[Error] Invalid format. Use format like '8U' or '5D'")
            return
        
        if not self._validate_request(floor, direction):
            return
        
        with open(self.requests_file, 'r') as f:
            requests = json.load(f)
        
        # Check if request already exists
        new_request = {"floor": floor, "direction": direction}
        if new_request not in requests:
            requests.append(new_request)
            with open(self.requests_file, 'w') as f:
                json.dump(requests, f)
            print(f"[External Call] Elevator called to Floor: {floor}, Direction: {direction}")
        else:
            print(f"[External Call] Request for Floor {floor}{direction} already exists")
    
    def run(self):
        print("[External Interface] Ready to accept requests...")
        print(f"Total floors: 0 to {self.total_floors - 1}")
        print("Request format: <floor><direction> (e.g., 8U, 5D)")
        print("Note: 0D and top-floor-U are invalid\n")
        
        while True:
            try:
                request = input("\nEnter request (e.g., 8U, 5D) or 'q' to quit: ")
                if request.lower() == 'q':
                    break
                self.call_elevator(request)
            except KeyboardInterrupt:
                break

if __name__ == "__main__":
    interface = ExternalInterface(total_floors=10)
    interface.run()