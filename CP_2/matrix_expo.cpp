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
https://www.geeksforgeeks.org/matrix-exponentiation/

e.g -> Fibonaci
| F(n)   |  =  | 1 1 |  x  | F(n-1) |
| F(n-1) |     | 1 0 |     | F(n-2) |

From Following We obtained this ->

| F(n)   |  =  | 1 1 |^(n-1)  x  | F(1) |
| F(n-1) |     | 1 0 |           | F(0) | 

F(n) = result[0][0] {where result = R.H.S obtained after multuplication}
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

/*
Throwing Dice :-

| F(n)   |    =  | 1 1 1 1 1 1 | * | F(n-1) | 
| F(n-1) |       | 1 0 0 0 0 0 |   | F(n-2) |
| F(n-2) |       | 0 1 0 0 0 0 |   | F(n-3) |
| F(n-3) |       | 0 0 1 0 0 0 |   | F(n-4) |
| F(n-4) |       | 0 0 0 1 0 0 |   | F(n-5) |
| F(n-5) |       | 0 0 0 0 1 0 |   | F(n-6) |

From Following We obtained this ->

| F(n)   |    =  | 1 1 1 1 1 1 |^(n-5) * | F(5) | 
| F(n-1) |       | 1 0 0 0 0 0 |         | F(4) |
| F(n-2) |       | 0 1 0 0 0 0 |         | F(3) |
| F(n-3) |       | 0 0 1 0 0 0 |         | F(2) |
| F(n-4) |       | 0 0 0 1 0 0 |         | F(1) |
| F(n-5) |       | 0 0 0 0 1 0 |         | F(0) |

Obtained via Observing similarity
*/

int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n; cin>>n;
        if(n<5){
            vi v = {0,1,2,4,8};
            cout<<v[n];
        }
        else{
            Matrix mid = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
            Matrix left = {{16},{8},{4},{2},{1},{1}};
            mid = matrix_power(mid, n-5);
            Matrix result = multiply(mid, left);
            cout<<result[0][0];
        }
    }

}



// ███████╗██╗███╗   ██╗██╗███████╗██╗  ██╗    ██╗    ██╗██╗  ██╗ █████╗ ████████╗    ██╗   ██╗ ██████╗ ██╗   ██╗    ███████╗████████╗ █████╗ ██████╗ ████████╗    ██╗
// ██╔════╝██║████╗  ██║██║██╔════╝██║  ██║    ██║    ██║██║  ██║██╔══██╗╚══██╔══╝    ╚██╗ ██╔╝██╔═══██╗██║   ██║    ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝    ██║
// █████╗  ██║██╔██╗ ██║██║███████╗███████║    ██║ █╗ ██║███████║███████║   ██║        ╚████╔╝ ██║   ██║██║   ██║    ███████╗   ██║   ███████║██████╔╝   ██║       ██║
// ██╔══╝  ██║██║╚██╗██║██║╚════██║██╔══██║    ██║███╗██║██╔══██║██╔══██║   ██║         ╚██╔╝  ██║   ██║██║   ██║    ╚════██║   ██║   ██╔══██║██╔══██╗   ██║       ╚═╝
// ██║     ██║██║ ╚████║██║███████║██║  ██║    ╚███╔███╔╝██║  ██║██║  ██║   ██║          ██║   ╚██████╔╝╚██████╔╝    ███████║   ██║   ██║  ██║██║  ██║   ██║       ██╗
// ╚═╝     ╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝     ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝          ╚═╝    ╚═════╝  ╚═════╝     ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝       ╚═╝