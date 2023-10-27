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
Count the number of distinct substrings that appear in a string.

3 Approaches ==>
 
1. Normal Trie DS -> The idea is create a Trie of all suffixes of given string. 
                    Once the Trie is constricted, our answer is total number
                    of nodes in the constructed Trie
                    T.C = [O(n^2)], S.C = [O(n)]
 
2. Suffix Array  -> First construct suffix-array and longext common prefix(lcp) array.
                    Using this 2 arr, we can find the tot no of distinct substring by keeping this fact in mind : 
                    If we look through the prefixes of each suffix of a string, we cover all substrings of that string. 
                    T.C = [O(n*logn)], S.C = [O(n)]
3. Suffix Trie   -> 
 
REFER GFG FOR BETTER UNDERSTANDING
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
 
// lcp array[i] = lcp of suff_of_string suf[i-1] & suf[i] 
vector<int> kasai(string txt, vector<int> suffixArr){  // kasai -> name of algo used
    int n = txt.size();
    vector<int> lcp(n, 0), invSuff(n, 0);
 
    for (int i=0; i<n; i++){invSuff[suffixArr[i]] = i;}
 
    int k = 0;
 
    for (int i=0; i<n; i++){
        if (invSuff[i] == n-1){
            k = 0;
            continue;
        }
        int j = suffixArr[invSuff[i]+1];
 
        while (i+k<n && j+k<n && txt[i+k]==txt[j+k]){k++;}
 
        lcp[invSuff[i]] = k; 
 
        if(k>0){k--;}
    }
 
    return lcp;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {   
        string s; cin>>s;
        int n = s.size();
 
        vector<int> suffix = build_suffix(s);
        vector<int> lcp = kasai(s, suffix);
 
        int tot = (n*(n+1))/2;
 
        for(int x : lcp){
            tot -= x;
        }
 
        // ans = tot_no_of_substring_possible - sum_of_lcp_array
        cout<<tot<<"\n";
        
    }
 
}
 
 
