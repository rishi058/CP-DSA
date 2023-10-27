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
A border of a string is a prefix that is also a suffix of the string but not the whole string. For
example, the borders of abcababcab are ab and abcab.
Your task is to find all border lengths of a given string.
*/

void computeLPSArray(const string &str, vector<int> &lps) {
    int n = str.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
 
    while (i < n) {
        if (str[i] == str[len]) {
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
 
vector<int> findBorderLengths(const string &str) {
    int n = str.size();
    vector<int> lps(n);
    computeLPSArray(str, lps);
 
    vector<int> borderLengths;
    int len = lps[n - 1];
    while (len > 0) {
        borderLengths.push_back(len);
        len = lps[len - 1];
    }
    
    sort(all(borderLengths));
    return borderLengths;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        string str; cin>>str;
        vi temp = findBorderLengths(str);
        print(temp);
    }
 
}
