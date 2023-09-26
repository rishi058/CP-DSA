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

/*
Refer CP-Algorithms for better understanding.
Following implementation is taken from there.
Refer cf blogs for over-optimization of mo's algorithm.
*/

//*******************************************************************************************

unordered_map<int,int> mp;

void remove(int idx){  // TODO: remove value at idx from data structure
}

void add(int idx){  // TODO: add value at idx from data structure
}

int getAnswer(){  // TODO: extract the current answer of the data structure
}

//--------------------------------------------------------------------------------------------

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if(pow == 0){return 0;}
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, idx;
    Query(int a, int b, int c){l=a, r=b, idx=c;}

    //! following is optimized method to order the queries (call this function after initializing each Query)
    int64_t ord;
    inline void calcOrder(){
        ord = gilbertOrder(l, r, 21, 0);
    }

    //! use this for normal operator to order(when optimization isn't needed)
    // bool operator<(Query other) const {
    //     return make_pair(l / block_size, r) <
    //            make_pair(other.l / block_size, other.r);
    // }

};

//! when gilbertOrder is used -> use folloeing comparator for sorting.
bool compare(Query a, Query b){
    return a.ord < b.ord;
}

//! use this cmp func when you want little optimization over normal implementation.
// const int block_size ;
// bool cmp(pair<int, int> p, pair<int, int> q) {
//     if (p.first / BLOCK_SIZE != q.first / BLOCK_SIZE)
//         return p < q;
//     return (p.first / BLOCK_SIZE & 1) ? (p.second < q.second) : (p.second > q.second);
// }

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end(), compare);

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = getAnswer();
    }
    return answers;
}

//********************************************************************************************

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