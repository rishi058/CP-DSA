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
There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day
of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?
*/

int32_t main()
{
    RISHI
 
    // SIMULATION
 
    int n; cin>>n;
 
    vector<pair<pair<int,int>,int>> vp;
    F(0,n,i){
        int a, b;
        cin>>a>>b;
        vp.push_back({{a,b},i});
    }
    sort(all(vp));
 
    multiset<pair<int,int>> st;  // stores occupied room info -> {depart_time, room_no}
    
    int room_no = 0;
    vi ans(n);
 
    F(0,n,i){
        int a = vp[i].first.first, b = vp[i].first.second, id = vp[i].second;  // a = arrival, b = depart
        if(st.empty()){
            room_no++;
            st.insert({b, room_no});
            ans[id] = room_no;
        }
        else{
            pair<int,int> min = *st.begin();
 
            if(min.first < a){             // if least departure time room is less than curr arrival time -> vacant the room + add new        
                st.erase(st.begin());
                st.insert({b, min.second});
                ans[id] = min.second;
            }
 
            else{
                room_no++;
                st.insert({b, room_no});
                ans[id] = room_no;
            }            
        }
 
        // print2(st);
    }
 
    int mx = *max_element(all(ans));
    cout<<mx<<"\n";
    print(ans);
}
 
