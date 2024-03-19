#include <bits/stdc++.h>
using namespace std;

#define int long long
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

/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

struct Node {
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularLL{
public:
    Node *head = NULL;

    CircularLL(vector<int> v) {
        if (v.empty()){return;}

        head = new Node(v[0]);
        head->next = head;
        Node* current = head;

        for(int i=1; i<v.size(); ++i) {
            Node* newNode = new Node(v[i]);
            newNode->next = head;
            current->next = newNode;
            current = newNode;
        }
    }

    int len(){
        if (head == nullptr) return 0;

        int count = 1;
        Node* current = head->next;
        while (current != head) {
            count++;
            current = current->next;
        }
        return count;
    }

    void delete_node(Node* nodeToDelete) {
        if (head == nullptr || nodeToDelete == nullptr) return;

        if (nodeToDelete == head) {
            Node* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                lastNode->next = head->next;
                delete head;
                head = lastNode->next;
            }
        } else {
            Node* current = head;
            while (current->next != head) {
                if (current->next == nodeToDelete) {
                    current->next = nodeToDelete->next;
                    delete nodeToDelete;
                    return;
                }
                current = current->next;
            }
        }
    }

};

int32_t main()
{
    RISHI
    int n, k;
    cin>>n>>k;
    k++;

    vi v;
    F(1,n+1,i){v.push_back(i);}
    CircularLL A(v);
    
    int i=0;
    while(A.len()>0){
        Node *next;

        if(i%k==0){
            cout<<A.head->data<<" ";
            i++;
            next = A.head->next;
            A.delete_node(A.head);
        }
        else{
            i++;
            A.head = A.head->next;
        }
    }
    

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝