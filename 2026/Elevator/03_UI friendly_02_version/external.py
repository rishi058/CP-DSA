import json
import os

class ExternalInterface:
    def __init__(self):
        self.requests_file = os.path.join(os.path.dirname(__file__), "elevator_requests.json")
        self._init_requests_file()
    
    def _init_requests_file(self):
        if not os.path.exists(self.requests_file):
            with open(self.requests_file, 'w') as f:
                json.dump([], f)
    
    def call_elevator(self, floor):
        with open(self.requests_file, 'r') as f:
            requests = json.load(f)
        
        if floor not in requests:
            requests.append(floor)
            with open(self.requests_file, 'w') as f:
                json.dump(requests, f)
            print(f"[External Call] Elevator called to Floor: {floor}")
        else:
            print(f"[External Call] Request for Floor {floor} already exists")
    
    def run(self):
        print("[External Interface] Ready to accept requests...")
        while True:
            try:
                floor = input("\nEnter floor to call elevator (or 'q' to quit): ")
                if floor.lower() == 'q':
                    break
                floor = int(floor)
                self.call_elevator(floor)
            except ValueError:
                print("Invalid input. Enter a number.")
            except KeyboardInterrupt:
                break

if __name__ == "__main__":
    interface = ExternalInterface()
    interface.run()