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

int32_t main()
{
    RISHI
    int T = 1;
    cin>>T;
    while(T--)
    {
        int n; cin >> n;

        vector<int> v(n);
        F(0,n,i){cin >> v[i];}

        string str; cin >> str;

        int sz = sqrt(n + .0) + 1;
        // int sz = sqrt(n) + 1;

        vi a, b;
        // vector<string> vec(str.size());
        vector<int> helper_xor_1(sz);
        // vector<int> helper_xor_2(2*sz);
        vector<int> helper_xor_0(sz);

        F(0,n,i){
            if (str[i] == '1'){
                helper_xor_1[i / sz] ^= v[i];
            }
            else{
                helper_xor_0[i / sz] ^= v[i];
            }
        }

        int queries; cin >> queries;

        while (queries--){
            int x; cin >> x;

            if (x == 1){
                int l,r; cin>>l>>r;
                l--; r--;

                for(int i = l; i <= r;){  /// find xxoorr pre calc

                    if (i % sz == 0 && i + sz - 1 <= r){
                        swap(helper_xor_0[i / sz], helper_xor_1[i / sz]);
                        i += sz;
                    }
                    else{
                        // agar .
                        helper_xor_0[i / n] ^= v[i];
                        helper_xor_1[i / n] ^= v[i];
                        ++i;
                    }
                }
            }

            else{
                
                int bitt; cin >> bitt;
                int ress = 0;
                /*
                print(ress);
                cout<<str<<" ";
                */
                if (bitt == 0){
                    for(int i = 0; i < sz; i++){
                        ress ^= helper_xor_0[i];
                    }
                }
                /*
                print(ress);
                cout<<str<<"\n";
                */
                else{
                    for(int i = 0; i < sz; i++){
                        ress ^= helper_xor_1[i];
                    }
                }
                // anss...
                cout<<ress<<" ";
            }

        }
        
        cout<<"\n";

    }

}




// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝