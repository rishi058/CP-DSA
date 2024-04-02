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
CSES : Giant Pizza

Uolevi's family is going to order a large pizza and eat it together. A total of n family
members will join the order, and there are m possible toppings. The pizza may have any
number of toppings.
Each family member gives two wishes concerning the toppings of the pizza. The wishes are
of the form "topping c is good/bad". Your task is to choose the toppings so that at least one
wish from everybody becomes true (a good topping is included in the pizza or a bad topping
is not included).

Giant Pizza (Approach = 2-SAT) -->
 
Conjunctive Normal Form (CNF) :- it is a conjunction (AND) of clauses, where every clause is a disjunction (OR).
        E.g -> [(A U B) ^ (B U C U ~A) ^ (~C U B)] .. etc.
 
Problem :- Find any value of A,B,C such that the given statement is True.
Note    :- It is a NP(non-deterministic polynomial) complete problem, i.e hard to solve efficiently for large instances.
 
2-SAT(satisfiability) or 2-CNF = problem of SAT where every clause having only 2 terms.
        E.g -> [ (A1 U B1) ^ (A2 U B2) ^ (A3 U B3) ] .. etc.
This can be solved in poynomial time, O(n+m)
 
for a CNF or 2-SAT to be true, each of its clause needs to be true.
 
Refer GFG for more. 
*/
 
const int N = 2e5+5;        // take twice as cosntraint
bool vis[N];
int comp[N];
vector<int> adj[N], adjT[N];
vector<int> ord;
int k = 0;
 
void dfs1(int u){
    vis[u] = true;
    for(int v : adj[u]){if(!vis[v]){dfs1(v);}}
    ord.push_back(u);
}
 
void dfs2(int u){
    vis[u] = true;
    comp[u] = k;
    for(int v : adjT[u]){if(!vis[v]){dfs2(v);}}
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, m;                   // {no. of people(wishes), no. of toppings}
        cin>>n>>m;                  // {n = no. of clauses, 2*m = no. of variables(bcz 'a' and '~a' is taken as diffrent nodes)}
         
        F(0,n,i){
            int u, v;                // ('u' U 'v') = [ ('~u' -> 'v') ^ ('~v' -> 'u') ]  // boolean properties
            char a, b;
            cin>>a>>u>>b>>v;
            if(a=='-'){u = 2*m-u+1;}
            if(b=='-'){v = 2*m-v+1;}
 
            int _u = 2*m-u+1, _v = 2*m-v+1;             // ~
            adj[_u].push_back(v), adj[_v].push_back(u);
            adjT[v].push_back(_u), adjT[u].push_back(_v);    // rev_adj
        }
 
        /*
        after constructing the following graph -> find Strongly Connected Components(SCC)->(use kosaraju algo)
        if any SCC contains 'u' & '~u' both, then it is not possible to make the CNF true.
        */  
 
        // F(1,2*m+1,i){cout<<i<<" : "; print(adj[i]);}
        for(int i = 1; i <= 2*m; i++){
            if(!vis[i]){dfs1(i);}
        }   
 
        memset(vis,0,sizeof vis);
        reverse(all(ord));
 
        for(int x : ord){
            if(!vis[x]){dfs2(x);}
            k++;
        }
 
        vector<char> ans;
        for(int i=1; i<=m; i++){
            if(comp[i]==comp[2*m-i+1]){break;}
            ans.push_back(comp[i]>comp[2*m-i+1]?'+':'-');
        }
 
        if(ans.size()==m){
            print(ans);
        }
        else{cout<<"IMPOSSIBLE\n";}
    }
 
}
 
