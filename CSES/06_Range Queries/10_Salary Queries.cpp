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
Salaries Query :-
A company has n employees with certain salaries. Your task is to keep track of the salaries and process queries.

1. If elements range where from 0 to 1e7, we can simply do it by building segment_tree_sum of freq_arr.
2. But here range is from 0 to 1e9, therefore we will store freq of 1-100 in idx 0, and so_on.
3. to find the freq of elements b/w (l,r) round l & r, and use segment_tree_range_sum_query, 
4. for left-over we can do it brute-forcely by using map<int,int>;
*/
 
class segment{
public:
	vector<int> tree;
	int n ;
 
	segment(){}
	segment(vector<int>&arr){build(arr);}
 
	void build(vector<int>&arr){
		n = arr.size();
		tree.resize(2*n, 0);
 
		for(int i=0; i<n; i++){tree[n+i]=arr[i];}
 
		for(int i=(n-1); i>0; --i){
			tree[i] = tree[i<<1] + tree[i<<1 | 1];	
		}
	}
 
	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = tree[i] + tree[i^1];
		}
	}
 
	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res += tree[l++];}
			if(r&1){res += tree[--r];}
		}
		return res;
	}
 
};
 
int bucket_no(int x){
    if(x % 100 == 0){x--;}  // 1-100 in block 0 but 100/100 = 1
    return (x / 100);
}
 
int calc(int lo, int hi, map<int,int>& mp){   // this is more optimized than find freq[a] to freq[b]
    int res = 0;
    auto it = mp.lower_bound(lo);
    while(it != mp.end() && it->first <= hi){
        res += it->second;
        it++;
    }
    return res;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,q;
        cin>>n>>q;
 
        vi salary(n);
        map<int,int> freq;
        vi cnt(1e7+1, 0);
 
        F(0,n,i){
            cin>>salary[i];
            freq[salary[i]]++;
            int idx = bucket_no(salary[i]);
            cnt[idx]++;
        }
 
        segment tree(cnt);
 
        while(q--){
            char c; cin>>c;
            if(c=='!'){
                int idx, val;
                cin>>idx>>val;
                int prev_salary = salary[idx-1];
                salary[idx-1] = val;
    
                int prev_bucket = bucket_no(prev_salary);
                int new_bucket = bucket_no(val);
    
                cnt[prev_bucket]--;  // it is better to keep track of cnt, rather than using seg-tree 
                cnt[new_bucket]++;
                freq[prev_salary]--;
                freq[val]++;
    
                tree.updateTreeNode(prev_bucket, cnt[prev_bucket]);
                tree.updateTreeNode(new_bucket,  cnt[new_bucket]);
            }
            else{
                int a, b;
                cin>>a>>b;
                int l = bucket_no(a), r = bucket_no(b);
 
                int ans = calc(a, min((l+1)*100, b), freq);
                ans  = ans + ((l!=r) ? calc(max(a, r*100 + 1), b, freq) : 0);
                ans  = ans + tree.query(l+1, r-1);
 
                cout << ans << '\n';
            }
        }
 
        
    }
 
}
