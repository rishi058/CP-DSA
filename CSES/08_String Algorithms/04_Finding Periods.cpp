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
A period of a string is a prefix that can be used to generate the whole string by repeating
the prefix. The last repetition may be partial. For example, the periods of abcabca are abc,
abcabc and abcabca.
Your task is to find all period lengths of a string.
*/

// Compute the longest proper prefix which is also a proper suffix (LPS array)
vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0; // Length of the current longest prefix suffix
    
    for (int i = 1; i < n; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
 
// Find all period lengths of a given string
vector<int> findPeriodLengths(const string &text) {
    vector<int> lps = computeLPS(text);
    int n = text.size();
    vector<int> periodLengths;
 
    int len = lps[n - 1];
    while (len > 0) {
        periodLengths.push_back(n - len);
        len = lps[len - 1];
    }
    
    periodLengths.push_back(n); // The entire string is also a period
    
    return periodLengths;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        string str; cin>>str;
        vi ans = findPeriodLengths(str);
        print(ans);
    }
 
}
