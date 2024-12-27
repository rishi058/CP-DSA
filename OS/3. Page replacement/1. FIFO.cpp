#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename dStruct>
void print(dStruct& vName){for(auto &it : vName){cout<<it<<" ";} cout<<"\n";}
template <typename dStruct>
void print2(dStruct& vName){for(auto &it : vName){cout<<"{"<<it.first<<", "<<it.second<<"} ";} cout<<"\n";}

const int mod = 1e9 + 7;
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------
// Best implementation is using Linked List
// First In First Out

class Queue {

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    ListNode *head, *tail;
    int ct = 0;

public:
    Queue() : head(nullptr), tail(nullptr) {} 

    void push(int x) { 
        ListNode* newNode = new ListNode(x);
        if (!tail) { head = tail = newNode; } // If the queue is empty
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ct++;
    }

    int pop() {
        if (!head) {throw std::underflow_error("Queue is empty");}

        int result = head->val;
        ListNode* temp = head;
        head = head->next;
        if (!head) { tail = nullptr; } // If the queue becomes empty

        delete temp; ct--;
        return result;
    }

    int peek() { 
        if (!head) {throw std::underflow_error("Queue is empty");}
        return head->val;
    }

    bool size() { 
        return ct;
    }

    ~Queue() { // Destructor to free allocated memory
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        
    }

}


//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝