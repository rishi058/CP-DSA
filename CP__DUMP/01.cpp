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

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

bool isPrime(int n){
    if(n==1){return false;}
    if(n==2 || n==3){return true;}
    if(n%2==0 || n%3==0){return false;}

    for(int i=5; i*i<=n; i+=6){
        if(n%i==0 || n%(i + 2)==0){
            return false;
        }
    }

    return true;
}

int findSum(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

map<int,int> primeFact(int n) { // Upgraded version..
    map<int,int> mapp;

    while(n % 2 == 0){
        mapp[2]++;
        n = n/2;
    }

    while(n%3==0){
        mapp[3]++;
        n/=3;
    }

    for(int i = 5; i*i<=n; i += 6){
        if(n%i==0){
            while(n % i == 0){
                mapp[i]++;
                n = n/i;
            }
        }
        if(n%(i+2)==0){
            while(n % (i+2) == 0){
                mapp[i+2]++;
                n = n/(i+2);
            }
        }
        
    }

    if(n>2){mapp[n]++;}

    return mapp;
}

int smithNum(int n) {
    if(isPrime(n)){return 0;}
    int sum = findSum(n);
    map<int,int> mp = primeFact(n);
    int sum2 = 0;
    for(auto it : mp){
        sum2 += findSum(it.first);
    }
    return sum==sum2;
}

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        
    }

}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝