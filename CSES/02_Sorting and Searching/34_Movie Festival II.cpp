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
In a movie festival, n movies will be shown. Syrjälä's movie club consists of k members,
who will be all attending the festival.
You know the starting and ending time of each movie. What is the maximum total number of
movies the club members can watch entirely if they act optimally?
*/

bool cmp(pair<int,int>&a, pair<int,int>&b){
    return a.second<b.second;
}
 
int32_t main()
{
    RISHI  // SIMULATION
    int n, k;
    cin>>n>>k;
 
    vector<pair<int,int>> vp;
    F(0,n,i){
        int a, b;
        cin>>a>>b;
        vp.push_back({a,b});
    }
 
    sort(all(vp), cmp);
    
    multiset<int> st;      // stores the ending time of movies, watching by k people
    F(0,k,i){st.insert(0);}
 
    int ans = 0;
    F(0,n,i){
        auto it = st.upper_bound(vp[i].first); 
        // checking if any person has ending time less than the starting time of the curr_movie.
        // i.e find a val <= start_time in st.
        if(it==st.begin()){continue;}
        st.erase(--it);
        st.insert(vp[i].second);
        ans++;
    }
 
    cout<<ans;
 
}
