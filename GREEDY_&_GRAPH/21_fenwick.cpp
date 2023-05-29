#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define Rev(a,b,i) for (int i = a; i >= b; i--)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define inf LONG_LONG_MAX
#define Min LONG_LONG_MIN

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

1 Compute the sum of the first i elements. 
2 Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.

One efficient solution is to use Segment Tree that performs both operations in O(Logn) time.
An alternative solution is Binary Indexed Tree, which also achieves O(Logn) time complexity 
for both operations. Compared with Segment Tree(4*n-space), Binary Indexed Tree(n-space) requires 
less space and is easier to implement.

rangeSum(l, r) = getSum(r) – getSum(l-1).

Xtra h.w --> 2D - Fenwick implementation for matrices.

*/

// https://leetcode.com/problems/range-sum-query-mutable/description/

class fenwick{              
public:

    vector<int> bit;

    fenwick(){};
    fenwick(vector<int>&val){initialize(val);}

    void initialize(vector<int>&val){
        int n = val.size();
        bit.resize(n+1, 0);
        for(int i=0; i<n; i++){
            update(i+1, 0, val[i]);
        }
    }

    // NOTE :- all queries is 1-based indexing.
    int getPrefixSum(int idx) { 
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx)){
            sum += bit[idx];
        }
        return sum;
    }

    int getRangeSum(int l, int r){
        return getPrefixSum(r) - getPrefixSum(l-1);
    }

    // NOTE :- also update the "val" after updating the tree.
    void update(int idx, int curr_val, int new_val){  
        int diff = new_val - curr_val;
        // basically this func dont update instead add val to curr_val.
        for (; idx < bit.size(); idx += idx & (-idx)){
            bit[idx] += diff;
        }
    }
};


int32_t main()
{
    RISHI

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝