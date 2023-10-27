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

/*
Given a string and patterns, find for each pattern the first position (1-indexed) where it appears in the string.
*/

vector<int> build_suffix(string &S) {
    int n = S.size();
    vector<int> sa;
    for (int i = n - 1; i >= 0; --i) {
        sa.push_back(i);
    }
    stable_sort(sa.begin(), sa.end(), [&](int a, int b) { return S[a] < S[b]; });
 
    vector<int> classes(n);
    for (int i = 0; i < n; ++i) {
        classes[i] = S[i];
    }
    for (int len = 1; len < n; len *= 2) {
        vector<int> c = classes;
        for (int i = 0; i < n; i++) {
            classes[sa[i]] =
                i > 0 && c[sa[i - 1]] == c[sa[i]] && sa[i - 1] + len < n && c[sa[i - 1] + len / 2] == c[sa[i] + len / 2]
                    ? classes[sa[i - 1]]
                    : i;
        }
        vector<int> cnt(n);
        iota(cnt.begin(), cnt.end(), 0);
        vector<int> s = sa;
        for (int i = 0; i < n; i++) {
            int s1 = s[i] - len;
            if (s1 >= 0)
                sa[cnt[classes[s1]]++] = s1;
        }
    }
    return sa;
}
 
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
			tree[i] = min(tree[i<<1], tree[i<<1 | 1]);	
		}
	}
 
	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 1e9;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = min(tree[l++],res);}
			if(r&1){res = min(tree[--r],res);}
		}
		return res;
	}
 
};
 
int BS_1st_nd_last(vi &suffixArr, string &text, string &pattern, bool first){
 
    int res = -1;
    int low=0, high=text.size()-1, k = pattern.size();
 
    while(low<=high){
        int mid = low + (high-low)/2 ;
        int idx = suffixArr[mid];
        string curr = text.substr(idx,k);
 
        if(curr==pattern){
            res = mid; 
            if(first){high = mid - 1;}
            else{low = mid+1;}
        }
        else if(curr<pattern){low = mid+1;}
        else{high = mid-1;}
 
    }
 
    return res;
 
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        string text; cin>>text;
        int n = text.size();
        vector<int> suffixArray = build_suffix(text);
 
        segment tree(suffixArray);
 
        int q; cin>>q;
        while(q--){
            string pattern; cin>>pattern;
 
            int ind1 = BS_1st_nd_last(suffixArray, text, pattern, 1);
            int ind2 = BS_1st_nd_last(suffixArray, text, pattern, 0);
 
            if(ind1==-1){cout<<"-1\n";}
            else{cout<<tree.query(ind1, ind2)+1<<"\n";}
        } 
        
    }
 
}
