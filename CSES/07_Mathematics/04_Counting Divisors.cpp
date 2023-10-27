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
Given n integers, your task is to report for each integer the number of its divisors.
For example, if c = 18, the correct answer is 6 because its divisors are 1, 2, 3, 6, 9, 18.
*/

const int MAX = 1e6+1;
int factors[MAX];
 
void facto(){
    for(int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            factors[j]++;
        }///
    }
}
 
int32_t main()
{
    RISHI
    facto();
    int T; cin>>T;
    while(T--)
    {
        int n; cin>>n;
        int ans = factors[n];
        cout<<ans<<"\n";
    }
}
