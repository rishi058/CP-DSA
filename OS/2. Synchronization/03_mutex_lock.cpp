#include <bits/stdc++.h>
using namespace std;

//!------------------------------------------------------------------
/*
A Mutex is used to provide mutual exclusion, ensuring that only one thread can enter a critical section of code at a time.
This prevents conflicts and data inconsistencies that can occur when multiple threads access shared resources concurrently.

There is ownership associated with mutex because only owner can release the lock.
Its functions based up on locking mechanism.
Only one thread can acquire mutex at a time.

Mutex can be locked multiple times by the same thread, but it needs to be unlocked an equivalent number of times before
other threads can acquire the Mutex.

DisAdv : 
1. Contention, 2. Deadlock, 3. Debugging, 4. Starvation of High priority threads.

*/
//!------------------------------------------------------------------

mutex mtx;

// Suppose this is a critical section.
void printInt(int x){
    mtx.lock();
    cout<<"Integer: "<<x<<"\n";
    mtx.unlock();
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
    return 0;
}
