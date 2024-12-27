#include <bits/stdc++.h>
using namespace std;

//!---------------------------------------------------------------------

/*
Peterson’s Solution:

Use case: Academic and theoretical scenarios for 2 threads only.
Drawback: Not practical for real-world systems or multi-threading.
Only for mutual exclusion
*/

//!---------------------------------------------------------------------

// Shared variables
atomic<bool> flag[2] = {false, false}; // Flag[i] = 1 represents that i'th thread is currently in critical section.
atomic<int> turn = 0;                 // Indicates whose turn it is

// Critical section
void printInt(int id, int x) {
    //! Entry Section
    int other = 1 - id; // The other process
    flag[id] = true;    // Set flag for the current process
    turn = other;       // Give turn to the other process
    while(flag[other] && turn==other){
        // Busy waiting
    }

    //!Critical Section
    cout<<"Thread "<<id<<" | ";
    this_thread::sleep_for(chrono::seconds(5));
    cout<<"Integer: "<<x<<"\n";

    //!Remainder Section

    //!Exit Section
    flag[id] = false; // Indicate this thread has left the critical section
}

//!---------------------------------------------------------------------

void printParallelInt() {
    vector<thread> threads;

    for (int i=0; i<2; i++) {
        // Lambda function
        threads.emplace_back([i]() { printInt(i, i+1);});
    }

    for (auto& th : threads) {
        th.join(); // Wait for all threads to complete
    }
}

//!---------------------------------------------------------------------

/*
The key reasons why lambda is necessary here:

State Capture: Lambda can capture shared variables (flag, turn) by reference using [&]
Scope Access: The shared variables need to be accessible to both threads
Synchronization: Both threads need to see the same memory locations for flag and turn
Memory Model: Lambda ensures proper memory visibility between threads
*/

//!---------------------------------------------------------------------

int main() {
    printParallelInt();
    return 0;
}
