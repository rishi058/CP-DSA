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

vector<int> getLPS(string &pat){
    int n = pat.size(), j = 0;   // ptr-j will iterate prefix only.
    vector<int> lps(n,0);

    for(int i=1; i<n; i++){
        if(pat[i] == pat[j]){lps[i] = ++j;}
        else if(j!=0){
            j = lps[j-1];
            i--;
        }
    }
    // print(lps);
    return lps;
}


int countPatternOccurrences(string &text, string &pat) {
    int n = text.size(), m = pat.size();
    vector<int> lps = getLPS(pat);

    int count = 0, j = 0;
    for(int i=0; i<n; i++){
        while(j>0 && text[i]!=pat[j]) {
            j = lps[j-1];
        }
        if(text[i]==pat[j]){
            j++;
            if(j==m){
                count++;
                j = lps[j-1];
            }
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
 
