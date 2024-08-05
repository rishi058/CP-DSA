#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;
const int mod = 1e9 + 7;


//------------------------------------------------------

int C[1001][1001];

void preNCR(){
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;

    for (int i = 1; i < 1000; i++){
        C[i + 1][i + 1] = 1;
        C[i + 1][0] = 1;

        for(int j = 1; j <= i; j++){
            C[i + 1][j] = (0LL + C[i][j] + C[i][j - 1])%mod;
        }
    }
}

//------------------------------------------------------

const int N = 1e6+1;
int fac[N];

int power(int x, int y){
    if(y==0){return 1;}
    if(y&1){return (1LL*x*power(x,y-1))%mod;}
    int tmp = power(x,y/2);
    return (1LL*tmp*tmp)%mod;
}
 
int modInv(int n){return power(n, mod - 2);}

int nCrMod(int n, int r){    // Fermat's Lttle Theorem
    if (n < r){return 0;}
    if (r == 0){return 1;}
    int num = fac[n];
    int den1 = modInv(fac[r]);
    int den2 = modInv(fac[n-r]);
    int tmp = (1LL*num*den1)%mod;
    return (1LL*tmp*den2)%mod;
}

void preCompute(){
    fac[0] = 1;
    for(int i=1; i<N; i++){
        fac[i] = (1LL* fac[i-1] * i) % mod;
    }
}

//------------------------------------------------------

int modInverse(long long a){
    long long ans = 1, b = mod - 2;
    while(b>0){
        if (b & 1){ans = ans * a % mod;}
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int nCr(int n, int r){
    if (n < (r << 1)){return nCr(n, n - r);}
    long long num = 1, den = 1;
    for (int i=1; i<=r; i++){
        num = num * n % mod;
        den = den * i % mod;
        n--;
    }
    return num * modInverse(den) % mod;
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

int main()
{
    RISHI
    preCompute();
    preNCR();
    int t=1;
    while(t--){
        cout<<nCrMod(5,2);
        // cout<<power(2,5);
        
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝