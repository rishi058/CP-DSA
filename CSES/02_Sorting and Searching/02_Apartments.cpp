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
There are n applicants and m free apartments. Your task is to distribute the apartments so
that as many applicants as possible will get an apartment.

Each applicant has a desired apartment size, and they will accept any apartment whose size
is close enough to the desired size.
*/

int32_t main()
{
    RISHI
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int n,m,k;
    cin>>n>>m>>k;
 
    vi req(n);
    F(0,n,i){cin>>req[i];}
 
    vi avail(m);
    F(0,m,i){cin>>avail[i];}
 
    sort(all(avail));
    sort(all(req));
    
 
    int i=0, j=0, ans = 0;
 
    while(i<n && j<m){
        int diff = abs(req[i]-avail[j]);
 
        if(diff<=k){
            ans++; i++; j++;
            
        }
        else if((req[i]-avail[j])>k){j++;}
        else{i++;}
 
    }
 
    cout<<ans<<" ";
}
 
