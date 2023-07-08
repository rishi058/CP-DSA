#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------
#define ull unsigned long long
ull power(ull x,int y, int p){
    ull res = 1; 
    x = x % p; 
    while (y > 0){
        if (y & 1){res = (res * x) % p;}
        y = y >> 1; 
        x = (x * x) % p;
    }
    return res;
}
 
ull modInv(ull n, int p){
    return power(n, p - 2, p);
}

ull nCrModP(ull n,int r, int p){
    // Fermat's Lttle Theorem
    if (n < r){return 0;}
    if (r == 0){return 1;}
    ull fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++){
        fac[i] = (fac[i - 1] * i) % p;
    }
 
    return (fac[n] * modInv(fac[r], p) % p* modInv(fac[n - r], p) % p)% p;
}
//-------------------------------------------------------------------


// #define mod (int)(1e9 + 7)
// int Fact[100001];
// int binExp(int n, int x)
// {
//     int ans = 1;
//     while (x)
//     {
//         if (x & 1)
//             ans = (ans * 1LL * n) % mod;
//         n = (n * 1LL * n) % mod;
//         x >>= 1;
//     }
//     return ans;
// }
// void CreateFactorial()
// {
//     Fact[0] = 1;
//     for (int i = 1; i <= 100000; i++)
//     {
//         Fact[i] = (i * 1LL * Fact[i - 1]) % mod;
//     }
// }
// int nCr(int N, int i)
// {
//     // N!/i!*(N-i)!
//     int numerator = Fact[N];
//     int denominator = (Fact[i] * 1LL * Fact[N - i]) % mod;
//     return (numerator * 1LL * binExp(denominator, mod - 2)) % mod;
// }

//-------------------------------------------------------------------

int32_t main()
{
    RISHI
    int t; cin>>t;
    while(t--)
    {
        
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝