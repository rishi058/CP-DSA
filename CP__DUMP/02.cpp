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
Distinct Values Queries :-
We can solve it via 2 approaches =  BIT, Mo's algorithm.

Twist : We cannot use frequency array as value of individual element can go upto 10^9. So what I'll simply use an unordered_map?
        No, unordered_map solution will time out due to high constant factor involved.

We can use simply Coordinate Compression method of to resolve it.
*/

//*******************************************************************************************

const int N = 2e5+1;
int freq[N];
int distinct;
vi v;
 
void remove(int idx){         // TODO: remove value at idx from data structure
    int val = v[idx];
    freq[val]--;
    if(!freq[val]){distinct--;}
}
 
void add(int idx){           // TODO: add value at idx from data structure
    int val = v[idx];
    if(!freq[val]){distinct++;}
    freq[val]++;
}
 
int getAnswer(){            // TODO: extract the current answer of the data structure
    return distinct;
}
 
//--------------------------------------------------------------------------------------------

const int block_size = 447;
 
struct Query{
    int l, r, idx;
    Query(int a, int b, int c){l=a, r=b, idx=c;}
 
    //! use this for normal operator to order(when optimization isn't needed)
    bool operator<(Query other) const {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
 
};
 
vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());
 
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
    while(T--)
    {
        int n, q;
        cin>>n>>q;

        v.resize(n);
        F(0,n,i){cin>>v[i];}

        map<int,int> coordinateCompress;
        int compressed_Num = 1;

        F(0,n,i){
            if(coordinateCompress.count(v[i])){
                v[i] = coordinateCompress[v[i]];
            }
            else{
                coordinateCompress[v[i]] = compressed_Num;
                v[i] = compressed_Num++;
            }
        }
 
        vector<Query> query;
        F(0,q,i){
            int l, r;
            cin>>l>>r;
            l--; r--;
            query.push_back(Query(l,r,i));
        }
 
        vi ans = mo_s_algorithm(query);
        for(int x : ans){cout<<x<<"\n";}
    }
 
}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝