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
You have to process n tasks. Each task has a duration and a deadline, and you will process
the tasks in some order one after another. Your reward for a task is d — f where d is its
deadline and f is your finishing time. (The starting time is O, and you have to process all
tasks even if a task would yield negative reward.)
What is your maximum reward if you act optimally?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vector<pair<int,int>> vp;
    F(0,n,i){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
    }
 
    sort(all(vp));
    // print2(vp);
    int time=0, reward=0;
    F(0,n,i){
        int finishing_time = time+vp[i].first;
        reward += vp[i].second - finishing_time;
        time = finishing_time;
    }
 
    cout<<reward;
}
 
