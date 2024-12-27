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

// for MFU use set<pair<int,int>, greater<pair<int,int>>> st;
//https://leetcode.com/problems/lru-cache/

class LRUCache {
private:
    int t = 1, n;

    unordered_map<int,int> mp;      // {key, value}
    unordered_map<int,int> time;    // {key, LRUT}
    set<pair<int,int>> st;          // {time, key}

    void insert(int &key, int &val){
        st.insert({t, key});
        time[key] = t;
        mp[key] = val;
        t++;
    }

    void removeLRU(){
        int key = st.begin()->second;
        mp.erase(key);
        time.erase(key);
        st.erase(st.begin());
    }

    void update(int &key, int &val){
        int oldt = time[key];
        time[key] = t;
        mp[key] = val;
        st.erase({oldt, key});
        st.insert({t, key});
        t++;
    }



public:
    LRUCache(int capacity){n = capacity;}
    
    int get(int key){
        if(!mp.count(key)){return -1;}

        int oldt = time[key];
        st.erase({oldt, key});
        st.insert({t, key});
        time[key] = t;
        t++;
        return mp[key];
    }
    
    void put(int key, int value){
        if(!mp.count(key)){   // it's a new key
            if(st.size()<n){
                insert(key, value);
            }
            else{   // st.size()==n, Remove LRU key
                removeLRU();
                insert(key, value);
            }
        }
        else{   // update
            update(key, value);
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