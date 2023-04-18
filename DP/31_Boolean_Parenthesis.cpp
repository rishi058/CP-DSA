#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F(a,b,i) for (int i = a; i < b; i++)
#define all(v) v.begin(), v.end()

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

/*

Given 2 arrays of Booleans and Symbols containing true, false, or, and, xor, functionss.
We have to Combine + Bracket Them in such a way so that Value of combinations is True..
Output the no. of ways of bracketing the array ..

*/

int countParenth(string symb, string oper, int n)
{
    int F[n][n], T[n][n];
 
    // Fill diagonal entries first
    // All diagonal entries in
    // T[i][i] are 1 if symbol[i]
    // is T (true).  Similarly,
    // all F[i][i] entries are 1 if
    // symbol[i] is F (False)
    for (int i = 0; i < n; i++) {
        F[i][i] = (symb[i] == 'F') ? 1 : 0;
        T[i][i] = (symb[i] == 'T') ? 1 : 0;
    }
 
    // Now fill T[i][i+1],
    // T[i][i+2], T[i][i+3]... in order
    // And F[i][i+1], F[i][i+2],
    // F[i][i+3]... in order
    for (int gap = 1; gap < n; ++gap)
    {
        for (int i = 0, j = gap;
             j < n; ++i, ++j)
        {
            T[i][j] = F[i][j] = 0;
            for (int g = 0; g < gap; g++)
            {
                // Find place of parenthesization using
                // current value of gap
                int k = i + g;
 
                // Store Total[i][k]
                // and Total[k+1][j]
                int tik = T[i][k] + F[i][k];
                int tkj = T[k + 1][j]
                  + F[k + 1][j];
 
                // Follow the recursive formulas
                // according
                // to the current operator
                if (oper[k] == '&') {
                    T[i][j] += T[i][k]
                            * T[k + 1][j];
                    F[i][j] += (tik * tkj
                                - T[i][k]
                                * T[k + 1][j]);
                }
                if (oper[k] == '|') {
                    F[i][j] += F[i][k]
                      * F[k + 1][j];
                    T[i][j] += (tik * tkj
                                - F[i][k]
                                * F[k + 1][j]);
                }
                if (oper[k] == '^') {
                    T[i][j] += F[i][k]
                      * T[k + 1][j]
                      + T[i][k]
                      * F[k + 1][j];
                    F[i][j] += T[i][k]
                            * T[k + 1][j]
                            + F[i][k] * F[k + 1][j];
                }
            }
        }
    }
    return T[0][n - 1];
}


int32_t main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin>>t;
    while(t--)
    {
        string boole = "TTFT";
        string symbol = "|&^";
        
        int n = symbol.size();
 
        // There are 4 ways
        // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
        // (T|((T&F)^T))
        cout << countParenth(symbol, boole, n);   
    }

}