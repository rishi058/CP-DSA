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

class lazySegment {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;
    
    void buildTree(vector<int>& arr) {
        for (int i = 0; i < n; ++i)
            tree[n + i] = arr[i];
        
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    
    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
public:
    lazySegment(vector<int>& arr) {
        n = arr.size();
        tree.resize(2 * n);
        lazy.resize(2 * n);
        buildTree(arr);
    }
    
    void rangeUpdate(int l, int r, int val) {
        l += n;
        r += n;
        
        while (l <= r) {
            if (l % 2 == 1) {
                lazy[l] += val;
                tree[l] += val;
                l++;
            }
            
            if (r % 2 == 0) {
                lazy[r] += val;
                tree[r] += val;
                r--;
            }
            
            l /= 2;
            r /= 2;
        }
    }
    
    int queryMin(int l, int r) {
        l += n;
        r += n;
        int res = INT_MAX;
        
        while (l <= r) {
            if (l % 2 == 1) {
                propagate(l, l / 2, (l / 2) + 1);
                res = min(res, tree[l]);
                l++;
            }
            
            if (r % 2 == 0) {
                propagate(r, (r / 2) - 1, r / 2);
                res = min(res, tree[r]);
                r--;
            }
            
            l /= 2;
            r /= 2;
        }
        
        return res;
    }
};


int32_t main()
{
    RISHI
    int n, q;
	cin>>n>>q;
	vi v(n);
	F(0,n,i){cin>>v[i];}

	lazySegment tree(v);

	while(q--)
	{
		char ch; cin>>ch;
		if(ch=='q'){
			int l, r;
			cin>>l>>r;
			l--; r--;
			cout<<tree.queryMin(l,r)<<"\n";
		}
		else{
			int l, r, x;
			cin>>l>>r>>x;
			l--; r--;
			tree.rangeUpdate(l,r,x);
		}
	}

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝