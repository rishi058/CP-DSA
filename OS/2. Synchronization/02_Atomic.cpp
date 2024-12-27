#include <bits/stdc++.h>
using namespace std;

/*
Atomic ensures operations on shared variables are performed atomically(one at a time).
Operations like read, write, increment, and compare-and-swap are performed as a single, uninterrupted execution.
Prevents race conditions without requiring explicit locks or mutexes.

Only suitable for simple operations. Complex synchronization might still require locks.
*/

//!---------------------------------------------------------------------

//!Run this part of code to see, How updating same var concurrently causes issue.

// int shared_counter = 1;  // Non-atomic shared variable

// void increment(int id) {
//     for(int i=0; i<100; i++) {
//         for(int j=0; j<100; j++){
//             int temp = shared_counter;     // Read
//             temp += 4;
//             this_thread::sleep_for(chrono::microseconds(500));  // This is IMP.
//             temp -= 2;
//             shared_counter = temp;        // Write
//         }
//     }
// }

//!---------------------------------------------------------------------

//!Run this part of code to see, How above issue is solved using Atomic operation.

atomic<int> shared_counter = 0;  // Atomic shared variable

// This function Adds 20000 to counter.
void increment(int id) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            shared_counter.fetch_add(4, memory_order_relaxed);  // Atomic increment
            this_thread::sleep_for(chrono::microseconds(500));  // Simulate delay
            shared_counter.fetch_sub(2, memory_order_relaxed);  // Atomic decrement
        }
    }
}

//!---------------------------------------------------------------------

int main() {
    int T = 1;
    while(T--){

        shared_counter = 0;
        vector<thread> threads;

        // Create two threads that increment the counter
        for(int i=0; i<2; i++) {
            threads.emplace_back(increment, i);
        }

        // Wait for threads to finish
        for(auto& th : threads) {
            th.join();
        }

        cout << "Final counter value: " << shared_counter << endl;
        cout << "Expected value: " << 40000 << endl;  // 2 threads × (1e4 *2) increments

    }

    return 0;
}