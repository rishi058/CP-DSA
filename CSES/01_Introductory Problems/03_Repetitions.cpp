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
 
#define mod 1e9+7
#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN
 
typedef long double ld;
typedef vector<int> vi;
 
/*---------------------------------------->   MAGIC STARTS   <--------------------------------------------*/

/*
You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest 
repetition in the sequence. This is a maximum-length substring containing only one type of character.
*/

int32_t main()
{
    RISHI
    string s;
    cin>>s;
 
    int n = s.size();
 
    int ans = 1;
    int ct = 1;
 
    F(1,n,i){
        if(s[i]==s[i-1]){ct++;}
        else{ct=1;}
        ans = max(ans, ct);
    }
 
    cout<<ans<<"\n";
}
