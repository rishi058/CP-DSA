const readline = require('readline');

// Helper to create delays (simulating travel time)
const sleep = (ms) => new Promise(resolve => setTimeout(resolve, ms));

class Elevator {
    constructor(totalFloors) {
        this.currentFloor = 1;
        this.totalFloors = totalFloors;
        this.status = 'IDLE'; // IDLE, MOVING, DOORS_OPEN
    }

    async moveTo(floor) {
        this.status = 'MOVING';
        while (this.currentFloor !== floor) {
            const direction = floor > this.currentFloor ? 1 : -1;
            await sleep(1000); // 1 second per floor
            this.currentFloor += direction;
            console.log(`[Elevator] Passing Floor ${this.currentFloor}...`);
        }
        this.status = 'DOORS_OPEN';
        console.log(`[Elevator] Arrived at Floor ${this.currentFloor}. Doors Opening.`);
    }
}

class ElevatorSystem {
    constructor(nFloors) {
        this.elevator = new Elevator(nFloors);
        this.queue = []; // FCFS Queue
        this.isProcessing = false;
        
        // Setup terminal input
        this.rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });
    }

    // External button press
    externalCall(floor) {
        console.log(`[System] External call registered at Floor ${floor}.`);
        this.queue.push(floor);
        this.processQueue();
    }

    async processQueue() {
        if (this.isProcessing || this.queue.length === 0) return;

        this.isProcessing = true;

        while (this.queue.length > 0) {
            const nextFloor = this.queue.shift();
            
            // 1. Move to the floor where the person is waiting
            console.log(`\n--- Picking up passenger at Floor ${nextFloor} ---`);
            await this.elevator.moveTo(nextFloor);

            // 2. Ask for the internal destination
            const destination = await this.askInternalCommand();
            
            // 3. Move to the destination
            console.log(`--- Taking passenger to Floor ${destination} ---`);
            await this.elevator.moveTo(destination);
            
            console.log(`--- Task Complete. Waiting for next request. ---`);
            await sleep(1000);
        }

        this.isProcessing = false;
        this.elevator.status = 'IDLE';
    }

    askInternalCommand() {
        return new Promise((resolve) => {
            this.rl.question(`[Internal] You are inside. Enter destination floor (1-${this.elevator.totalFloors}): `, (answer) => {
                const floor = parseInt(answer);
                if (isNaN(floor) || floor < 1 || floor > this.elevator.totalFloors) {
                    console.log("Invalid floor. Defaulting to Floor 1.");
                    resolve(1);
                } else {
                    resolve(floor);
                }
            });
        });
    }
}

// --- Run Simulation ---
const mySystem = new ElevatorSystem(10); // 10 floor system

console.log("Elevator System Started. Floor 1.");
console.log("Simulating external calls from Floor 3 and then Floor 5...");

mySystem.externalCall(3);
mySystem.externalCall(5);