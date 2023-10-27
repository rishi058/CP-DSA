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
Your task is to divide the numbers 1,2,…,n into two sets of equal sum.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
    
    int sum = (n*(n+1))/2;
 
    if(sum%2){cout<<"NO\n";}
    else{
        int target = sum/2;
        vi v(n);
        F(0,n,i){v[i]=i+1;}
 
        vi vis(n, 0);
        int curr = 0;
        int a = 0, b = n-1;
        if(n%2){b--;}
 
        vi ans1;
 
        while(curr!=target){
            ans1.push_back(v[a]);
            ans1.push_back(v[b]);
            curr += v[a];
            curr += v[b];
            vis[a] = 1; vis[b] = 1;
            a++; b--;
        }
 
        vi ans2;
        F(0,n,i){
            if(!vis[i]){
                ans2.push_back(v[i]);
            }
        }
 
        cout<<"YES\n";
        cout<<ans1.size()<<"\n";
        print(ans1);
        cout<<ans2.size()<<"\n";
        print(ans2);
 
    }
}
