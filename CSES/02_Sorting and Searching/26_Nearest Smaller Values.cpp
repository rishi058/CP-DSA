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
Given an array of n integers, your task is to find for each array position the nearest position to its left having a smaller value.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    stack<int> st;  // Stack to store indices of elements with potential smaller values
    vi ans(n,0);
 
    F(0,n,i){
        while(!st.empty() && v[st.top()]>=v[i]){
            st.pop();  // Remove elements with greater or equal values
        }
 
        if(!st.empty()){
            ans[i] = st.top()+1;  // Store index of nearest smaller element
        }
 
        st.push(i);  // Push the current index onto the stack
    }
    
    print(ans);
}
 
