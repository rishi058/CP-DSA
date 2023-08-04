#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n, k;
    cin>>n>>k;

    oset<int> st;
    F(1,n+1,i){st.insert(i);}

    int idx = k;
    while(!st.empty()){
        idx %= st.size();
        int x = *st.find_by_order(idx);
        cout<<x<<" ";
        st.erase(x);
        idx += k;
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝