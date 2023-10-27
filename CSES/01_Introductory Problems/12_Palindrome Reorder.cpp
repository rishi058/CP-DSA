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
Given a string, your task is to reorder its letters in such a way that it becomes a palindrome (i.e., it reads the same forwards and backwards).
*/

int32_t main()
{
    RISHI
    string s; cin>>s;
    int n = s.size();
 
    map<char,int> mp;
    F(0,n,i){mp[s[i]]++;}
 
    int ctOdd = 0;
    char x;
    for(auto it : mp){
        if(it.second%2){x=it.first; ctOdd++;}
    }
 
    if(ctOdd>1){cout<<"NO SOLUTION\n";}
 
    else if(n%2==0 && ctOdd==1){cout<<"NO SOLUTION\n";}
 
    else if(n%2==0){
        deque<char> temp;
        for(auto it : mp){
            int y = it.second/2;
            while(y--){
                temp.push_back(it.first);
                temp.push_front(it.first);
            }
        }
        string ans;
        while(!temp.empty()){ans.push_back(temp.back()); temp.pop_back();}
        cout<<ans<<"\n";
    }
 
    else{
        deque<char> temp;
        temp.push_back(x);
        for(auto it : mp){
            int y = it.second/2;
            while(y--){
                temp.push_back(it.first);
                temp.push_front(it.first);
            }
        }
        string ans;
        while(!temp.empty()){ans.push_back(temp.back()); temp.pop_back();}
        cout<<ans<<"\n";
    }
 
}
