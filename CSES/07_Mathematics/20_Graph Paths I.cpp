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
Consider a directed graph that has n nodes and m edges. Your task is to count the number
of paths from node 1 to node n with exactly k edges.
*/

/*
Matrix Exponentiation Approach :- 
Let’s first create an Adjacency matrix. We can see for the case of k=1,
the answer is the constructed Adjacency Matrix, for any 2 pair of nodes.
 
We Can observe that for k=2, answer is Adj_matrix^2;
Thus the solution of the problem is AdjMat^k;
 
T.C = O(n^3*log(k))
*/
 
using Matrix = vector<vector<int>>;
 
Matrix multiply(Matrix&A, Matrix&B){
    int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
    Matrix res(r1, vector<int>(c2,0));
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            for(int k=0; k<c1; k++){
                res[i][j] = (res[i][j] + (A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    return res;
}
 
Matrix matrix_power(Matrix& matrix, int k) {
    int n = matrix.size();
    Matrix result(n, vector<int>(n, 0));
 
    for (int i = 0; i < n; ++i) {result[i][i] = 1;}
 
    Matrix temp = matrix;
    while (k > 0) {
        if (k % 2 == 1) {
            result = multiply(result, temp);
        }
        temp = multiply(temp, temp);
        k /= 2;
    }
    
    return result;
}
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n,m,k; // nodes, edges, k;
        cin>>n>>m>>k;
        
        Matrix adj(n, vector<int>(n,0));
 
        for(int i=0; i<m; i++){
            int u, v;
            cin>>u>>v;
            u--; v--;
            adj[u][v]++;
        }
 
        Matrix res = matrix_power(adj,k);
        cout<<res[0][n-1];
    }
 
}
 
