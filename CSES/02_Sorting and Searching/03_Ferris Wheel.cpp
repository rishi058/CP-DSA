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
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for
each child.
Each gondola may have one or two children in it, and in addition, the total weight in a
gondola may not exceed c. You know the weight of every child.
What is the minimum number of gondolas needed for the children?
*/

int32_t main()
{
    RISHI
    
    int n,x;
    cin>>n>>x;
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    sort(all(v));
 
    int ans = 0;
    int a = 0, b = n-1;
    while(a<=b){
        if(a==b){ans++; break;}
        int sum = v[a]+v[b];
        if(sum<=x){
            ans++;
            a++;
            b--;
        }
        else{
            b--;
            ans++;
        }
    }
 
    cout<<ans<<"\n";
 
}
