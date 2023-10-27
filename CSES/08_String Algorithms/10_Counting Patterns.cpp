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
Given a string and patterns, count for each pattern the number of positions where it appears in the string.

Approach -> Binary Search of Suffix Array
 
T.C for building-suffix-array = (n*log(n))    [Advance Algorithm]
T.C per search                = (k*log(n))    {k=len(pattern)}
 
Total = 1 + 2 = (n+k)*log(n) = (n*logn)
 
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
        int q; cin>>q;
 
        vector<int> suffixArray = build_suffix(text);
        // print(suffixArray);
 
        while(q--){
            string pattern; cin>>pattern;
           
            int ind1 = BS_1st_nd_last(suffixArray, text, pattern, 1);
            int ind2 = BS_1st_nd_last(suffixArray, text, pattern, 0);
            if(ind1==-1){cout<<"0\n";}
            else{cout<<ind2-ind1+1<<"\n";}            
        }
 
    }
 
}
