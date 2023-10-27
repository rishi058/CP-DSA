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
Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm
divides it by two, and if n is odd, the algorithm multiplies it by three and adds one. The
algorithm repeats this, until n is one. For example, the sequence for n = 3 is as follows:
3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
Your task is to simulate the execution of the algorithm for a given value of n.
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    while(n!=1){
        cout<<n<<" ";
 
        if(n%2){
            n*=3;
            n++;
        }
        else{
            n/=2;
        }
 
    }
 
    cout<<n<<" ";
 
}
