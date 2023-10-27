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
A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ
in exactly one bit (i.e., their Hamming distance is one).
Your task is to create a Gray code for a given length n.
*/

int B2G(int num) {
    return num ^ (num >> 1);
}
 
string dec2bin(int dec, int n){
    string res;
    while(dec>0){
        int rem = dec%2;
        res.push_back(to_string(rem)[0]);
        dec/=2;
    }
    while(res.size()<n){
        res.push_back('0');
    }
    reverse(all(res));
    return res;
}
 
int32_t main()
{
    RISHI
    int n; cin>>n;
 
    F(0,(1<<n),i){
        int gray = B2G(i);
        cout<<dec2bin(gray, n)<<"\n";
    }
 
}
