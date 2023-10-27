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
Given a string and patterns, check for each pattern if it appears in the string.

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
            int k = pattern.size();
 
            int lo=0, hi=(n-1);
            bool ok = 0;
 
            while(lo<=hi){
                int mid = (lo+hi)/2;
                int idx = suffixArray[mid];
                string curr = text.substr(idx, k);
                if(curr==pattern){
                    ok = 1;
                    break;
                }
                if(curr<pattern){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
 
            if(ok){cout<<"YES\n";}
            else{cout<<"NO\n";}
 
        }
 
    }
 
}
