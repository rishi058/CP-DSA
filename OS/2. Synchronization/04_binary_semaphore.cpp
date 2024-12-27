#include<bits/stdc++.h>
using namespace std;

/*
!Binary Semaphore :
1. Its functions based up on signalling mechanism.
2. The thread which is having higher priority than current thread can also release binary semaphore and take lock.
3. Semaphore value is changed according to wait() and signal() operations.
4. Multiple number of threads can acquire binary semaphore at a time concurrently.
5. Unlike Mutex Binary semaphore have no ownership.
6. They are faster than mutex because any other thread/process can unlock binary semaphore.

!Producer-Consumer Problem :
It is a classic synchronization problem where producers generate data and place it in a shared buffer,
while consumers retrieve and process the data, requiring coordination to avoid buffer overflows and underflows.

The challenge is to ensure that the producer doesn’t add data to a full buffer and the consumer doesn’t 
remove data from an empty buffer while avoiding conflicts when accessing the buffer.

!NOTE : Producer & Consumer are 2 threads which run parallely.

This problem cannot be solved using Mutex only.
It can be solved with mutex + condition_variable. (required for signaling).
This combination(mutex + conditional_varialble) is also known as Binary Semaphore.
Conditional variables is used to signal conditions like "buffer empty" or "buffer full."

*/


vector<int> buffer;        // Shared buffer
const int BUFFER_SIZE = 5; // Max size of the buffer

void randomDelay(){
    int x = rand() % 11;
    this_thread::sleep_for(chrono::milliseconds(x*100));
}

//!------------------------------------------------------------------

//! Simulating Error in Producer-Consumer when only Mutex is used.
//! Rum 4-5 times to get ERROR.

mutex mtx;                 // Mutex for synchronization

void producer() {
    for (int i = 0; i < 10; ++i) {

        mtx.lock(); // Lock the critical section

        if(buffer.size() == BUFFER_SIZE){
            cout << "ERROR : buffer is full.\n";
            mtx.unlock(); // Unlock for consumer to proceed
            randomDelay(); // Simulate wait
            i--;  //retry
            continue;
        }

        buffer.push_back(i);
        cout << "Produced: " << i << " | "<<"Buffer Size : "<<buffer.size()<<"\n";

        mtx.unlock(); // Unlock for consumer

        randomDelay(); // Simulate production time
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {

        mtx.lock(); 

        if (buffer.empty()) {
            cout << "ERROR : buffer is empty.\n";
            mtx.unlock(); // Unlock for producer to proceed
            randomDelay(); // Simulate wait
            i--;
            continue;
        }

        int item = buffer.back();
        buffer.pop_back();
        cout << "Consumed: " << item << " | "<<"Buffer Size : "<<buffer.size()<<"\n";

        mtx.unlock();

        randomDelay(); // Simulate consumption time
    }
}

//!------------------------------------------------------------------

// Binary semaphores for synchronization
binary_semaphore producer_semaphore(1); // Initially open for producer
binary_semaphore consumer_semaphore(0); // Initially closed for consumer

void producer2() {
    for (int i = 0; i < 10; ++i) {
        producer_semaphore.acquire(); // Wait for producer semaphore

        if (buffer.size() < BUFFER_SIZE) {
            buffer.push_back(i);
            cout << "Produced: " << i << "\n";
        }

        consumer_semaphore.release(); // Notify consumer
        randomDelay(); // Simulate production time
    }
}

void consumer2() {
    for (int i = 0; i < 10; ++i) {
        consumer_semaphore.acquire(); // Wait for consumer semaphore

        if (!buffer.empty()) {
            int item = buffer.back();
            buffer.pop_back();
            cout << "Consumed: " << item << "\n";
        }

        producer_semaphore.release(); // Notify producer
        randomDelay(); // Simulate consumption time
    }
}

//!------------------------------------------------------------------

int main() {
    // thread t1(producer);
    // thread t2(consumer);

    // t1.join();
    // t2.join();

    thread producer_thread(producer2);
    thread consumer_thread(consumer2);
    thread producer_thread2(producer2);
    thread consumer_thread2(consumer2);

    // buffer size varies b/w 0 & 1 : Bcz its Binary-Semaphore.

    producer_thread.join();
    consumer_thread.join();
    producer_thread2.join();
    consumer_thread2.join();

    return 0;
}