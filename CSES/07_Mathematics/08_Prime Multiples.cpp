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
You are given k distinct prime numbers 01, a2,... and an integer n.
Your task is to calculate how many of the first n positive integers are divisible by at least
one of the given prime numbers.

INCLUSION EXCLUSION PRINCIPLE
 
e.g -> n( A U B ) = n(A) + A(B) - n(A & B) ;
 
Similarly : -
 
n(a1 U a2 U a3 ... U a'n) ==>
    [ n(a1) + n(a2) + ... + n(a'n) ] - [n(a1 & a2) + n(a2 & a3)...all possible pairs] + [n(a1 & a2 & a3) + n(a2 & a3 & a4)...all possible triplets] ....
 
We can observe group-size with odd counts are added and even count are subtracted...
 
Analogy with our problem --> 
    n(A) = ans for prime_no = A [i.e count of divisors <n]
    let N = 20, k = 2, prime = {2,5}
    {2} = {2,6,8,10,12,14,16,18,20} -> size = 10;
    {5} = {5,10,15,20} -> size = 4;
    {2x5 = 10} = {10,20} -> size = 2
 
    ans = n(2) + n(5) - n(10) = 10 + 4 - 2 = 12.
*/
 
 
bool isNthBitSet(int& number, int& n){
   int mask = 1 << n;
   return (number & mask) != 0;
}
 
int32_t main()
{
    RISHI
    int n, k;
    cin>>n>>k;
 
    vi v(k);
    F(0,k,i){cin>>v[i];}
 
    int ans = 0;
 
    for(int i=1; i<(1<<k); i++){
        bool isOdd = __builtin_popcount(i) % 2;  
        int temp = n;      // instead of dividing "n" by product of subset -> divide n each time by "prime" [to avoid large number error]
        for(int j=0; j<k; j++){
            if(isNthBitSet(i,j)){
                temp /= v[j];
            }
        }
 
        if(isOdd){ans+=temp;}
        else{ans-=temp;}
    }
 
    cout<<ans;
}
