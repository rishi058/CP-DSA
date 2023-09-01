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
#define inf HorizontalONG_HorizontalONG_MAX
#define Min HorizontalONG_HorizontalONG_MIN

typedef long double ld;
typedef vector<int> vi;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        F(0,n,i){cin>>grid[i];}
        

        vector<vi> Horizontal(m), Vertical(n);

        F(0,n,i){
            F(0,m,j){
                if (grid[i][j] == 'L') {
                    Horizontal[j].push_back(i);
                } else if (grid[i][j] == 'U') {
                    Vertical[i].push_back(j);
                }
            }
        }

        bool ok = true;

        for (auto &row : Horizontal) {
            if (row.size() % 2 != 0) {
                ok = false;
                break;
            }
        }

        for (auto &col : Vertical) {
            if (col.size() % 2 != 0) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << -1 << "\n";
            continue;
        }

        F(0,m,j){
            for (int k = 0; k < Horizontal[j].size(); k += 2) {
                int i1 = Horizontal[j][k];
                int i2 = Horizontal[j][k + 1];
                grid[i1][j] = 'W';
                grid[i2][j] = 'B';
                grid[i1][j + 1] = 'B';
                grid[i2][j + 1] = 'W';
            }
        }

        F(0,n,i){
            for (int k = 0; k < Vertical[i].size(); k += 2) {
                int j1 = Vertical[i][k];
                int j2 = Vertical[i][k + 1];
                grid[i][j1] = 'W';
                grid[i][j2] = 'B';
                grid[i + 1][j1] = 'B';
                grid[i + 1][j2] = 'W';
            }
        }

        for (auto &row : grid) {
            for (char x : row) {
                cout << x;
            }
            cout << "\n";
        }

        
    }

}