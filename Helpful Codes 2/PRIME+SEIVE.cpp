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


int32_t main()
{
    RISHI
    cout<<"000";

}