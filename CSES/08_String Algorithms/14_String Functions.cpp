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
We consider a string of n characters, indexed 1, 2, ... Your task is to calculate all values of
the following functions:
• z(i) denotes the maximum length of a substring that begins at position i and is a prefix
of the string. In addition, z(l) = O.
• T(i) denotes the maximum length of a substring that ends at position i, is a prefix of
the string, and whose length is at most i — 1.
*/

vector<int> computeLPSArray(string &pattern){
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    int i = 1;
 
    while (i < pattern.size()) {
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
 
vector<int> ZFunction(string& str) {
    int n = str.length();
    vector<int> z(n,0);
 
    int l = 0, r = 0;  // Rightmost prefix that matches the substring
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            // If i is within the current Z-box, we can use previously computed values.
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        // Expand the Z-box to the right if possible
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
        // Update the rightmost matching prefix
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
 
    return z;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        string str;
        cin>>str;
 
        int n = str.size();
        vector<int> pii = computeLPSArray(str);
        vector<int> Zfun = ZFunction(str);
 
        print(Zfun);
        print(pii);
 
    }
 
}
