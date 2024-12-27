#include <bits/stdc++.h>
// #include <thread>
// #include <mutex>
using namespace std;

/*

!WHAT IS CRITICAL SECTION PROBLEM (RACE CONDITION) ?

Critical Section refers to the part of code where threads access shared resources.
Since thread executes parallely, any execution can be interrupted in the middle.

A race condition ocurrs when two or more threads try to operate the shared resources at the same time.
The result of the change in data depends on the thread scheduling algorithm.
Here, both threads are "racing" to operate on the data.

!HOW TO HANDLE IT :

do {
    1. Entry Section: Controls the entry into the critical section and acquires a lock. Code here ensures mutual exclusion(using mutex or semaphore).

    2. Critical Section: Contains code that accesses shared resources. Only one process/thread can execute this section at a time

    3. Exit Section: Releases the lock and signals others that the critical section is available.

    4. Remainder Section: Executes other non-critical work.

} while (1); // Repeats the process indefinitely


!REAL LIFE EXAMPLE :

1. Printing in Shared Printers :

Scenario: Multiple users send documents to a shared printer at the same time. User A and User B's print jobs are submitted simultaneously.
Race Condition: If the system doesn’t synchronize access to the printer queue, print jobs might: Overwrite each other. Print documents in the wrong order.

2. Shared Database Updates:

Scenario: Two processes update the same database record concurrently.
Race Condition: If one process reads outdated data while the other updates it: Inconsistent data is saved, Database integrity is compromised.

*/


//!------------------------------------------------------------------

// EXAMPLE FOR SYNCHRONIZATION PROBLEM.
// IT IS PRINTING RUBBISH


// Suppose this is a critical section.
void printInt(int x){
    cout<<"Integer: "<<x<<"\n";
}


void printParallelInt(){

    vector<thread> threads;

    for(int i=1; i<=10; i++){
        // Direct function passing.
        threads.emplace_back(printInt, i);         

        // Use Lambda Function   
        // threads.emplace_back([i]() { printInt(i);});
    }

    for(auto &th : threads){
        th.join();               // Executing all the threads parallely.
    }

}


//!------------------------------------------------------------------

int main() {

    printParallelInt();
    /*
    Suppose Terminal act as a Page & printInt act as a printer.
    Req o/p should ne Integer : 1, Integer : 2, ...
    But due to synchronization issue. 
    printer is printing in wrong order.
    */
   
    return 0;
}
