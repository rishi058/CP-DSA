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
You are given a string of length n and a dictionary containing k words. In how many ways
can you create the string using the words?
*/

class TrieNode {
public:
    TrieNode *child[26];
    bool isWord = false;
    TrieNode(){for(auto&a : child){a = nullptr;}}
};
 
class Trie {
public:
    TrieNode* root;
    Trie(){root = new TrieNode();}
 
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
 
};
 
string res;
int sz;
vi dp;
 
int solve(int idx, Trie& db){
    if(idx==sz){return 1;}
    if(dp[idx]!=-1){return dp[idx];}
 
    TrieNode *start = db.root;
    int ans = 0;
    for(int i=idx; i<sz; i++){      // We are doing search starting from prefix..
        int pos = res[i]-'a';               // therefore integrating search function here to optimize
        if(!start->child[pos]){break;}
        if(start->child[pos]->isWord){
            ans = (ans+solve(i+1, db)) % mod;
        }
        start = start->child[pos];
    }
 
    return dp[idx] = ans;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        cin>>res;
 
        sz = res.size();
        dp.resize(sz,-1);
 
        Trie db;
        int n; cin>>n;
        F(0,n,i){
            string s; cin>>s;
            db.insert(s);
        }
 
        cout<<solve(0, db);
    }
 
}
