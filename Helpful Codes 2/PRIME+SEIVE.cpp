#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

const int N = 1e7+10;
vector<bool> is_prime(N,1);

void pre(){
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i<N; i++){
        if(is_prime[i]==true){
            for(int j=2*i; j<N; j+=i){      // n*(log(log(n))) time-complexity
                is_prime[j] = false;
            }
        }
    }
}

bool isPrime(int x){
    if(x==1){return 0;}
    if(x==2 || x==3){return 1;}
    if(x%2==0 || x%3==0){return 0;}
    for(int i=5; i*i<=x; i+=6){
        if(x%i==0 || x%(i+2)==0){return 0;}
    }
    return 1;
}


int32_t main()
{
    RISHI
    cout<<"000";

}