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
Consider a game where there are n children (numbered 1, 2, , n) in a circle. During the
game, every other child is removed from the circle until there are no children left. In which
order will the children be removed?
*/

int32_t main()
{
    RISHI
    int n; cin>>n;
 
    vi A, B;
    F(1,n+1,i){A.push_back(i);}
 
    bool sf2 = 1;     // start_from_2nd_element;
 
    while(A.size()>1){
        int i=0, bck = A.back();
 
        for(int x : A){
 
            if(sf2){
                if(i%2){cout<<A[i]<<" ";}
                else{B.push_back(A[i]);}
            }
            else{
                if(i%2==0){cout<<A[i]<<" ";}
                else{B.push_back(A[i]);}
            }
 
            i++;
        }
        if(bck==B.back()){sf2=0;}
        else{sf2=1;}
 
        A = B;
        B.clear();
    }
 
    cout<<A[0];
}
 
