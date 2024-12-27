#include <bits/stdc++.h>
using namespace std;

void printTime(){
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    cout << "Current time: " << put_time(localtime(&now_time), "%H:%M:%S") << "\n";
}

//!---------------------------------------------------------------------------
/*
Dining philospher problem :
'K' Philosophers are dining on a round table. There are 'K' forks(Chopstick) on the table. A philospher need exactly 2 fork to Eat.
There are three states of the philosopher: THINKING, HUNGRY, and EATING.

AIM : 
Avoid deadlock : Situation where each philosopher picks 1 fork.(Now no one can eat).
Avoid starvation : (1 or more philosopher never gets to Eat).
*/
//!-------------------------------------------------------------------------------

const int N = 5;

mutex forks[N];   // Mutexes representing forks
mutex cout_mutex; // Mutex for synchronizing console output
atomic<bool> is_waiting[N]; // Atomic array to track if a philosopher is waiting

void philosopher(int id) {
    int left_fork = id;                          // Fork on the left of the philosopher
    int right_fork = (id + 1) % N;               // Fork on the right of the philosopher

    while (true) {
        //! Thinking
        {
            lock_guard<mutex> lock(cout_mutex);   // lock until this scope is executed;
            cout << "Philosopher " << id << " is THINKING. ";
            printTime();
        }
        this_thread::sleep_for(chrono::seconds(2));

        //! Hungry
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " is HUNGRY and trying to pick up forks. ";
            printTime();
        }
        is_waiting[id] = true; // Mark philosopher as waiting

        //! Picking up forks
        while (!forks[left_fork].try_lock()) {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " is WAITING for the left fork. ";
            printTime();
            this_thread::sleep_for(chrono::seconds(1));
        }


        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " picked up the left fork. ";
            printTime();
        }

        while (!forks[right_fork].try_lock()) {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " is WAITING for the right fork. ";
            printTime();
            this_thread::sleep_for(chrono::seconds(1));
        }


        is_waiting[id] = false; // Philosopher is no longer waiting

        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " picked up the right fork. ";
            printTime();
        }

        //! Eating
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " is EATING. ";
            printTime();
        }
        this_thread::sleep_for(chrono::seconds(2));

        //! Putting down forks
        forks[right_fork].unlock();
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " put down the right fork. ";
            printTime();
        }

        forks[left_fork].unlock();
        {
            lock_guard<mutex> lock(cout_mutex);
            cout << "Philosopher " << id << " put down the left fork. ";
            printTime();
        }
    }
}

//!-------------------------------------------------------------------------------
/*
Pseudo Code For Case of Deadloack Implementation in Dining Philosopher Problem.

void philosopher(int id) {
    int left_fork, right_fork;               

    while (true) {
        !THINKING

        !WAITING
        is_waiting[id] = true; 

        !Picking up forks
        while (!forks[left_fork].try_lock()) {
            Busy Waiting
        }
        while (!forks[right_fork].try_lock()) {
            Busy Waiting
        }

        is_waiting[id] = false;

        !Eating
        
        !Putting down forks
        forks[right_fork].unlock();
        forks[left_fork].unlock();
    }
}

*/
//!-------------------------------------------------------------------------------

int main() {
    vector<thread> philosophers;

    // Initialize the waiting array
    for (int i = 0; i < N; ++i) {
        is_waiting[i] = false;
    }

    // Create philosopher threads
    for (int i = 0; i < N; ++i) {
        philosophers.emplace_back(philosopher, i);
    }

    // Join philosopher threads (infinite loop for demonstration purposes)
    for (auto& philosopher : philosophers) {
        philosopher.join();
    }

    /*
    Here Deadlock ocurrs when A philosopher is stuck in indefinte waiting.
    Run 2-3 times to check the case.
    */

    return 0;
}
