from collections import deque
import asyncio, time

class Elevator:
    def __init__(self):
        self.current_floor = 0 # Ground floor

    def moveTo(self, floor):
        while self.current_floor != floor:
            if self.current_floor < floor:
                self.current_floor += 1
            else:
                self.current_floor -= 1
            time.sleep(1)  # Simulate time taken to move one floor
            print(f"[Elevator] Floor: {self.current_floor}")


class ElevatorSystem:
    def __init__(self):
        self.elevator = Elevator()
        self.requests = deque()
        self.isProcessing = False

    async def externalRequest(self, floor):
        print(f"[System] Call from Floor: {floor}")
        self.requests.append(floor)
        # print(f"Queue length: {len(self.requests)}")
        if not self.isProcessing:
            asyncio.create_task(self.processRequests())

    async def processRequests(self):
        self.isProcessing = True
        while self.requests:
            pickup = self.requests.popleft()
            print(f"--- Pickup at Floor: {pickup} ---")
            self.elevator.moveTo(pickup)

            dest = int(input("Enter destination: "))
            print(f"--- Dropoff at Floor: {dest} ---")
            self.elevator.moveTo(dest)
        self.isProcessing = False  

async def main():
    system = ElevatorSystem()
    await system.externalRequest(3)
    await system.externalRequest(7)
    await system.externalRequest(2)

if __name__ == "__main__":
    asyncio.run(main())