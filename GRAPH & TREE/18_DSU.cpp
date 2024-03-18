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

class DSU{
public :
    vector<int> parent, Size, Rank;
    
    void makeNodes(int sz){ // this func create n independent nodes automatically
        for(int i=0; i<sz; i++){ make(i); }
    }

    DSU(int sz){
        parent.resize(sz, 0);   // use 0, for avoiding bugs.
        Size.resize(sz, 0);
        Rank.resize(sz, 0);
    }

    void make(int v){ parent[v] = v; Size[v] = 1; } 

    int find(int v){                                      // Recursion 
        if(v==parent[v]) { return v; }
        else { return parent[v] = find(parent[v]); }     // path compression 
    }

    void UnionBySize(int a, int b){   
        a = find(a); b = find(b);
        if( a!=b ){   
            if(Size[a] < Size[b]) { swap(a,b); }      
            parent[b] = a; Size[a] += Size[b];
        }
    }

    void UnionByRank(int a, int b){
        a = find(a); b = find(b);
        if(a!=b){
            if(Rank[a]<Rank[b]){
                parent[a] = b;
            }
            else if(Rank[a]>Rank[b]){
                parent[b] = a;
            }
            else{
                parent[b] = a; Rank[a]++;
            }
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