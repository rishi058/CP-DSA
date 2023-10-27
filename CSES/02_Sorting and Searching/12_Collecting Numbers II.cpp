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

/*
You are given an array that contains each number between 1.. .n exactly once. Your task is
to collect the numbers from 1 to n in increasing order.

On each round, you go through the array from left to right and collect as many numbers as
possible.

Given m operations that swap two numbers in the array, your task is to report the number
of rounds after each operation.
*/

int32_t main()
{
    RISHI
    int n,m;
    cin>>n>>m;
 
    vi v(n), pos(n+2);
 
    F(0,n,i){
        cin>>v[i];
        pos[v[i]] = i+1;
    }
 
    pos[n+1] = n+1;
 
    int ans = 1;
    F(1,n+1,i){
        if(pos[i-1]>pos[i]){ans++;}
    }
 
    while(m--){
        int a, b;
        cin>>a>>b;
        a--; b--;
 
        if(v[a]>v[b]){swap(a,b);}
 
        if(pos[v[a]-1] > pos[v[a]]){ans--;}
        if(pos[v[a]] > pos[v[a]+1]){ans--;}
        
        if(v[a]+1!=v[b]){if(pos[v[b]-1] > pos[v[b]]){ans--;}}
        if(pos[v[b]] > pos[v[b]+1]){ans--;}
          
        pos[v[a]] = b+1;
        pos[v[b]] = a+1;
 
        if(pos[v[a]-1] > pos[v[a]]){ans++;}
        if(pos[v[a]] > pos[v[a]+1]){ans++;}
 
        if(v[a]+1!=v[b]){if(pos[v[b]-1] > pos[v[b]]){ans++;}}
        if(pos[v[b]] > pos[v[b]+1]){ans++;}
 
        swap(v[a], v[b]);
        cout<<ans<<"\n";
    }
 
}
