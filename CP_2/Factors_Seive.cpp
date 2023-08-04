#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------


const int MAX = 2e5+1;
vector<int> factors[MAX];

void facto(){
    for(int i = 1; i < MAX; i++) {
        for (int j = i; j < MAX; j += i) {
            factors[j].push_back(i);
        }///
    }
}

int32_t main()
{
    RISHI
    facto();
    int t; cin>>t;
    while(t--)
    {
        int i=0;
        for(auto v : factors){
            cout<<i<<" : ";
            for(int x : v){
                cout<<x<<" ";
            }
            cout<<"\n"; i++;
        }
        
    }

}