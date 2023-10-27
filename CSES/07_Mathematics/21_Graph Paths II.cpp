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
Consider a directed weighted graph having n nodes and m edges. Your task is to calculate
the minimum path length from node 1 to node n with exactly k edges.
*/

using Matrix = vector<vector<int>>;
 
Matrix multiply(Matrix&A, Matrix&B){
    int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
    Matrix res(r1, vector<int>(c2,inf));
 
    for(int i=0; i<r1; i++){
        for(int j=0; j<c2; j++){
            for(int k=0; k<c1; k++){
                if(A[i][k]!=inf && B[k][j]!=inf){                   //
                    res[i][j] = min(res[i][j], A[i][k]+B[k][j]);    //
                }
            }
        }
    }
    return res;
}
 
Matrix matrix_power(Matrix& matrix, int k) {
    int n = matrix.size();
    Matrix result(n, vector<int>(n, inf));     //
    for(int i=0; i<n; i++){result[i][i]=0;}    //
 
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
        
        Matrix adj(n, vector<int>(n,inf));
 
        for(int i=0; i<m; i++){
            int u, v, wt;
            cin>>u>>v>>wt;
            u--; v--;
            adj[u][v] = min(adj[u][v], wt);
        }
 
        Matrix res = matrix_power(adj,k);
        if(res[0][n-1]==inf){cout<<-1;}
        else{cout<<res[0][n-1];}
    }
 
}
