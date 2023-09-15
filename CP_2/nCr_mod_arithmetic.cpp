#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

const int mod = 1e9 + 7;
const int N = 1e6+1;
int fac[N];


int power(int x, int y){
    int res = 1; 
    x = x % mod; 
    while (y){
        if (y & 1){res = (res * x) % mod;}
        y >>= 1; 
        x = (x * x) % mod;
    }
    return res;
}
 
int modInv(int n){
    return power(n, mod - 2);
}

int nCrMod(int n, int r){
    // Fermat's Lttle Theorem
    if (n < r){return 0;}
    if (r == 0){return 1;}
    return ( ( ( ( fac[n] * modInv(fac[r] ) ) % mod ) * modInv(fac[n - r]) ) % mod ) % mod;
}

void preCompute(){
    fac[0] = 1;
    for(int i=1; i<N; i++){
        fac[i] = (fac[i-1] * i) % mod;
    }
}

//------------------------------------------------------

/*
NOTE :-

Modular Division :-

-->  (a/b) % mod = ( a*modInv(b) ) % mod;
--> modInv(b) = ( b^(mod-2) ) % mod  [ can only be achieved via binExp ]

Modular Sub :-

--> (a-b) % M = ((a % M) - (b % M) + M) % M

*/

int32_t main()
{
    RISHI
    preCompute();
    int t=1;
    while(t--)
    {
        int ok = modInv(784);
        cout<<ok;
        
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝