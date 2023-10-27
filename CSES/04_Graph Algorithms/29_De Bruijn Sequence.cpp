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
Your task is to construct a minimum-length bit string that contains all possible substrings of
length n. For example, when n = 2, the string 00110 is a valid solution, because its
substrings of length 2 are 00, 01, 10 and 11.

de-bruijn sequence (refer gfg) :- 
Given =>		ct_of_elements          = k,
				elements_list           = list[k],
				length of permutation   = n,
 
print the smallest arr which consists 'all the permutation of len=n build from list elements' as a sub-arr exactly once. 
 
Approach :- 
construct a directed graph with k^(n-1) nodes.  [Each node corresponds to a permutation of size n-1]
Each node should have "k" out_going edges.      [Every edge corresponds to one of the k elements]
How to join edges 						    =>  [https://www.youtube.com/watch?v=FpeBsBwJMbc&ab_channel=taptap]
 
A--->B, if when we remove first element of A and add a something to end, & it becomes B.  
 
the Eulerain circuit of the graph is the req ans.
 
cses question :-
given   => [ ct = 2 & list = {0,1} ]
input   => n,
output  => de-bruijn sequence.
*/
 
const int N = (1<<14) + 2;	   // 2^(15-1) + safety
 
vector<pair<int,char>> adj[N];
unordered_map<string,int>  mp;
string mp2[N];
 
int k = 1;
 
void pre(string s, int &n){   // mapping (node_no. -> string) & vice-versa
	if(s.size()==n-1){
		mp[s]=k; mp2[k] = s; k++; return;
	}
	pre(s+'0', n);
	pre(s+'1', n);
}
 
 
 
int32_t main()
{
	RISHI
	int T = 1;
	while(T--)
	{
		int n; cin>>n;
 
		if(n==1){cout<<"01\n"; continue;}
 
		pre("", n);
 
		int ct = 1<<(n-1);				// k^(n-1)
		for(int i=1; i<=ct; i++){
            string x = mp2[i];
			x.erase(x.begin());
			adj[i].push_back({mp[x+'0'], '0'});
			adj[i].push_back({mp[x+'1'], '1'});
		}
		
		//eulerian path always exists
    	string path;
    	stack<pair<int,char>> st;
    	st.push({1,'#'});
		
    	while(!st.empty()){
    	    auto [node, ch1] = st.top();
 
    	    if(adj[node].empty()){
				if(ch1!='#'){
					path += ch1;
				}
				st.pop();
			}
 
    	    else{
    	        auto [child, ch2] = adj[node].back();
				adj[node].pop_back();
    	        st.push({child, ch2});
    	    }
 
    	}
 
    	path += mp2[1];
    	cout<<path<<"\n";
 
	}
 
}
