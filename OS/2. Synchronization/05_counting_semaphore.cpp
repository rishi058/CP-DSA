#include<bits/stdc++.h>
using namespace std;

// Shared buffer and constraints
vector<int> buffer;
const int BUFFER_SIZE = 5;

void randomDelay(){
    int x = rand() % 11;
    this_thread::sleep_for(chrono::milliseconds(x*100));
}

// Semaphores for synchronization
counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Tracks empty slots in the buffer
counting_semaphore<BUFFER_SIZE> full_slots(0);            // Tracks filled slots in the buffer
mutex buffer_mutex;                                       // Mutex for protecting buffer access

void producer(int producer_id) {
    for (int i = 0; i < 10; ++i) {
        empty_slots.acquire(); // Wait for an empty slot
        {
            lock_guard<mutex> lock(buffer_mutex);
            buffer.push_back(i);
            cout << "Producer " << producer_id << " produced: " << i << " | Buffer size: " << buffer.size() << "\n";
        }
        full_slots.release(); // Signal a filled slot
        this_thread::sleep_for(chrono::milliseconds(100)); // Simulate production time
    }
}

void consumer(int consumer_id) {
    for (int i = 0; i < 10; ++i) {
        full_slots.acquire(); // Wait for a filled slot
        int item = -1;
        {
            lock_guard<mutex> lock(buffer_mutex);
            item = buffer.back();
            buffer.pop_back();
            cout << "Consumer " << consumer_id << " consumed: " << item << " | Buffer size: " << buffer.size() << "\n";
        }
        empty_slots.release(); // Signal an empty slot
        this_thread::sleep_for(chrono::milliseconds(150)); // Simulate consumption time
    }
}

int main() {
    thread producer1(producer, 1);
    thread producer2(producer, 2);
    thread consumer1(consumer, 1);
    thread consumer2(consumer, 2);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}
