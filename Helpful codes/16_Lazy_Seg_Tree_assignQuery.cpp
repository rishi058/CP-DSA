#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
// #define F(a,b,i) for (int i = a; i < b; i++)
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

//!------------------------ Practice like you've never won. Perform like you've never lost. ------------------------

/*
Cses - Range Updates and Sums
Can be done only with lazy propagation of segment trees approach.

Code by CP-algorithms + (mrsac7)
*/

#define F first
#define S second

class lazySegment{
private:
    int n;
    vector<pair<int,int>> seg;      // {tree, lazy}
    vector<int> mark;               // aditional for assign query

    void push(int k) {
        if (mark[k]) {
            mark[k] = 0;
            seg[2*k].F = seg[2*k + 1].F = seg[k].F/2;
            seg[2*k].S = seg[2*k + 1].S = 0;
            mark[2*k] = mark[2*k + 1] = 1;
        }   
    }

    void update(int v, int a, int b, int k, int x, int y) {
        if (b < x || a > y) return;
        if (a<=x && b>=y) {
            seg[k].S += v;
            return;
        }
        int h = min(b,y) - max(a,x) + 1;
        push(k); 
        seg[k].F += h*v;
        int d = (x+y)/2;
        update(v, a, b, 2*k, x, d);
        update(v, a, b, 2*k + 1, d + 1, y);
    }

    int assign(int v, int a, int b, int k, int x, int y) {
        if (b < x || a > y) return seg[k].F + (y - x + 1)*seg[k].S;
        if (a <= x && b >= y) {
            seg[k].F = (y-x+1)*v;
            seg[k].S = 0;
            mark[k] = 1; 
            return seg[k].F;
        }
        push(k); 
        int d = (x+y)/2;
        seg[2*k].S += seg[k].S,  seg[2*k + 1].S += seg[k].S;
        seg[k].S = 0;
        seg[k].F = assign(v, a, b, 2*k, x, d) + assign(v, a, b, 2*k + 1, d + 1, y);
        return seg[k].F;

    }
    int sum(int a, int b, int k, int x, int y) {
        if (b < x || a > y) return 0;
        if (a <= x && b >= y) {
            return seg[k].F + (y-x+1)*seg[k].S;
        }
        push(k); 
        seg[k].F += (y-x+1)*seg[k].S;
        seg[2*k].S += seg[k].S, seg[2*k + 1].S += seg[k].S;
        seg[k].S = 0;
        int d = (x+y)/2;
        return sum(a, b, 2*k, x, d) + sum(a, b, 2*k + 1, d + 1, y);
    }
public:
    lazySegment(vector<int>&v){
        int sz = v.size();
        n = 1<<(int)ceil(log2(sz));
        seg.resize(4*sz);
        mark.resize(4*sz,0);
        for(int i=0; i<v.size(); i++){
            updateRange(i,i,v[i]);
        }
    }

    int getSum(int l, int r){return sum(l,r,1,0,n-1);}
    void setRange(int l, int r, int x){assign(x,l,r,1,0,n-1);}
    void updateRange(int l, int r, int x){update(x,l,r,1,0,n-1);}
};

int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;

        vi v(n);
        for(int i=0; i<n; i++){cin>>v[i];}

        lazySegment tree(v);

        while(q--){
            int type; cin>>type;

            if(type==1){            // Increase each value in range[a,b] by x
                int a, b, x;
                cin>>a>>b>>x;
                a--; b--;

                tree.updateRange(a,b,x);

            }
            else if(type==2){       // Set each value in range[a,b] to x
                int a, b, x;
                cin>>a>>b>>x;
                a--; b--;

                tree.setRange(a,b,x);
            }
            else{                   // Calculate the sum of values in range[a,b]
                int a, b;
                cin>>a>>b;
                a--; b--;

                int ans = tree.getSum(a,b);
                cout<<ans<<"\n";
            }
        }
        
    }

}



//      ██╗  █████╗  ██╗    ██████╗ ██╗  ██╗ ██████╗  ███████╗ ███████╗   ██████╗   █████╗  ███╗   ███╗
//      ██║ ██╔══██╗ ██║   ██╔════╝ ██║  ██║ ██╔══██╗ ██╔════╝ ██╔════╝   ██╔══██╗ ██╔══██╗ ████╗ ████║
//      ██║ ███████║ ██║   ╚█████╗  ███████║ ██████╔╝ █████╗   █████╗     ██████╔╝ ███████║ ██╔████╔██║
// ██╗  ██║ ██╔══██║ ██║    ╚═══██╗ ██╔══██║ ██╔══██╗ ██╔══╝   ██╔══╝     ██╔══██╗ ██╔══██║ ██║╚██╔╝██║
// ╚█████╔╝ ██║  ██║ ██║   ██████╔╝ ██║  ██║ ██║  ██║ ███████╗ ███████╗   ██║  ██║ ██║  ██║ ██║ ╚═╝ ██║
//  ╚════╝  ╚═╝  ╚═╝ ╚═╝   ╚═════╝  ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚══════╝ ╚══════╝   ╚═╝  ╚═╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝