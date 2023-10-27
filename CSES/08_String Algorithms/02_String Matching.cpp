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
Given a string and a pattern, your task is to count the number of positions where the
pattern occurs in the string.
*/

void computeLPSArray(const string &pattern, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
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
}
 
int countPatternOccurrences(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
 
    vector<int> lps(m, 0);
    computeLPSArray(pattern, lps);
 
    int count = 0;
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
 
        if (j == m) {
            count++;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
 
    return count;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        string str, pat;
        cin>>str>>pat;
        cout<<countPatternOccurrences(str,pat);
    }
 
}
 
