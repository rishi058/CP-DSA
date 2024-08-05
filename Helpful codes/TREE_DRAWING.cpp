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

/*
Its a implementation of Reingold-Tilford Algorithm.
This is used for tidy tree drawing such that no nodes overlap each other & tree width is minimal.
Basically we have to assign coordinates {x,y} to each node in a tree.

Reference :- 
https://github.com/zchtodd/recurser/blob/master/static/recurser.js
https://rachel53461.wordpress.com/2014/04/20/algorithm-for-drawing-trees/

Algorithtm Steps :
1. initializeX();   // assign x = {0,1,2} sibling traversal & compute modifier value.
2. updateXY();      // run prefixSum on nodes.x with modifier value + assign depth level wise.
3. makePositive();  // make the x coordinate of all nodes positive by adding minVal to each node.

4. fixNodeConflicts(15);    // Imp & Hard 1.
   Left contour, Right Contour is used.
   if right-most node of a left subtree is overlapping with left-most node of its is adjacent node subtree (adj = same leve, & neighbour).
   then shift the right subtree by its dif , so its doesn't overlap.   
*/

const int N = 10000;
vector<int> adj[N];
map<int,pair<float,float>> pos;
float modifier[N];

void initializeX(int n){ // n - total nodes
    for(int i=1; i<=n; i++){
        if(adj[i].empty()){continue;}

        for(int j=0; j<adj[i].size(); j++){
            pos[adj[i][j]] = {j,0};         // add 2*j, 3*j, for some edge cases
        }
    }

    for(int i=1; i<=n; i++){
        if(adj[i].empty()){continue;} 
        // computing & assigning modifier [orgX - desiredX]
        float mid = pos[i].first - (pos[adj[i][0]].first + pos[adj[i].back()].first)/2.00;  
        modifier[i] = mid;
    }
}

void updateXY(int root, int depth, float modSum){
    pos[root].first += modSum;
    pos[root].second = depth;
    for(int child : adj[root]){
        updateXY(child, depth+1, modSum + modifier[root]);
    }
}

void makePositive(){
    float minPos = 0;
    for(auto &it : pos){
        minPos = min(minPos, it.second.first);
    }

    if(minPos < 0){
        for(auto &it : pos){
            it.second.first -= minPos;
        }
    }
}

float getRB(int node){
    while(!adj[node].empty()){
        node = adj[node].back();
    }
    return pos[node].first;
}

float getLB(int node){
    while(!adj[node].empty()){
        node = adj[node][0];
    }
    return pos[node].first;
}

void ShiftSubtree(int node, float shift){
    pos[node].first += shift;
    for(int child : adj[node]){
        ShiftSubtree(child, shift);
    }
}

void fixNodeConflicts(int root){
    for(int child : adj[root]){
        fixNodeConflicts(child);   // doing opr from child to par - IMP
    }

    if(adj[root].empty()){return;}
    

    for(int j=0; j<adj[root].size()-1 ; j++){
        int child1 = adj[root][j];
        int child2 = adj[root][j+1];
        
        float RB_ofLeft = getRB(child1);   // rightmost bottom node of left subtree 
        float LB_ofRight = getLB(child2);  // leftmost bottom node of right subtree 
        if(RB_ofLeft >= LB_ofRight){                              // add = for some edge cases
            ShiftSubtree(child2, RB_ofLeft - LB_ofRight + 1);      // add RB-LB+1/+2... for some edge cases
        } 
    }
    
}

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        // adj[1] = {2,3};
        // adj[2] = {4};
        // adj[3] = {5,6};
        // adj[6] = {7};
        adj[1] = {2,3,4};
        adj[2] = {5,6};
        adj[6] = {7,8};
        adj[4] = {9,10};
        adj[10] = {11,12,13,14,15};
    

        initializeX(15);
        updateXY(1, 1, 0);
        makePositive();
        fixNodeConflicts(1);

        // cout<<getRB(1);
        // cout<<pos[6].first<<"\n";

        for(int i=1; i<=15; i++){
            cout<<i<<" : "<<pos[i].first<<"\n";
            // " "<<pos[i].second<<"\n";
        }
        
    }

}