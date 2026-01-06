#include<bits/stdc++.h>
using namespace std;

class Elevator{
public:
    int curr_floor = 0;

    void moveTo(int floor){
        while(curr_floor != floor){
            curr_floor += (curr_floor < floor) ? 1 : -1;
            this_thread::sleep_for(chrono::milliseconds(1000));
            cout<<"[Elevator] Floor: "<<curr_floor<<endl;
        }
    }
};

class ElevatorSystem{
    Elevator elevator;
    int requested_floor = -1;

public:
    void externalRequest(int floor){
        cout<<"[System] Call from Floor: "<<floor<<endl;
        requested_floor = floor;
        processRequests();
    }

    void processRequests(){
        int pickup = requested_floor;
        cout<<"--- Pickup at Floor: "<<pickup<<" ---"<<endl;
        elevator.moveTo(pickup);
         
        int dest;
        cout<<"Enter destination: "; cin>>dest;
        cout<<"--- Dropoff at Floor: "<<dest<<" ---"<<endl;
        elevator.moveTo(dest);
    }
};

int main(){
    ElevatorSystem system;
    cout<<"ELEVATOR STARTED AT FLOOR 0.\n\n";
    system.externalRequest(3);
    system.externalRequest(5);
}