#include <bits/stdc++.h>
using namespace std;

#define int long long
#define tuple array<int, 3>
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

int getNumPerfectPackaging(vector<int>& p) {
    const int MOD = 1e9 + 7;
    vector<int> dp0(6, 1);
    vector<int> dp1(6, 0);

    for (int i = 1; i < p.size(); ++i) {
        vector<int> c(6, 0);
        for (int s = 1; s < 6; ++s) {
            c[s] = (c[s - 1] + dp0[s]) % MOD;
        }
        int tot = c[5];
        for (int s = 1; s < 6; ++s) {
            if (p[i] > p[i - 1]) {
                dp1[s] = c[s - 1];
            } else if (p[i] < p[i - 1]) {
                dp1[s] = (tot - c[s]) % MOD;
            } else {
                dp1[s] = (tot - dp0[s]) % MOD;
            }
        }
        dp0 = dp1;
        dp1 = vector<int>(6, 0);
    }

    int result = 0;
    for (int i = 1; i < 6; ++i) {
        result = (result + dp0[i]) % MOD;
    }
    return result;
}

int32_t main()
{
    RISHI
    int T = 1;
    // cin>>T;
    while(T--)
    {
        vi v = {5};
        cout<<getNumPerfectPackaging(v);
        
    }

}


//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝