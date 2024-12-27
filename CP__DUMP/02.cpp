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


int subarrayGCD(vector<int>& nums, int gcdK) {
    int cnt = 0, n = nums.size();

    for (int idx = 0; idx < n; idx++){
        if (nums[idx] == gcdK){
            cnt++;
        }
    }

    for (int idx = 0; idx < n; idx++) {
        bool flag = false;
        int curr = nums[idx];

        for (int jdx = idx + 1; jdx < n; jdx++) {
            if (nums[jdx] % gcdK != 0){break;}

            curr = __gcd(curr, nums[jdx]);

            if (curr == gcdK){flag = true;}

            if (flag){cnt++;}
        }
    }

    return cnt;
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