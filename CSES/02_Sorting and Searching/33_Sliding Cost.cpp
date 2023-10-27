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
You are given an array of n integers. Your task is to calculate for each window of k elements,
from left to right, the minimum total cost of making all elements equal.
You can increase or decrease each element with cost c where c is the difference between
the new and the original value. The total cost is the sum of such costs.
*/

int k;
multiset<int> up;
multiset<int> low;
int sUp, sLow;
 
void ins(int val) {
	int a = *low.rbegin();
	if (a < val) {
		up.insert(val);
		sUp += val;
		if (up.size() > k / 2) {
			int moving = *up.begin();
			low.insert(moving);
			sLow += moving;
			up.erase(up.find(moving));
			sUp -= moving;
		}
	} else {
		low.insert(val);
		sLow += val;
		if (low.size() > (k + 1) / 2) {
			int moving = *low.rbegin();
			up.insert(*low.rbegin());
			sUp += moving;
			low.erase(low.find(*low.rbegin()));
			sLow -= moving;
		}
	}
}
 
void er(int val) {
	if (up.find(val) != up.end()) up.erase(up.find(val)), sUp -= val;
	else low.erase(low.find(val)), sLow -= val;
	if (low.empty()) {
		int moving = *up.begin();
		low.insert(*up.begin());
		sLow += moving;
		up.erase(up.find(*up.begin()));
		sUp -= moving;
	}
}
 
int med() { return (k % 2 == 0) ? 0 : (*low.rbegin()); }
 
 
int32_t main()
{
    RISHI
    int n;
    cin>>n>>k;
 
    vi v(n);
    F(0,n,i){cin>>v[i];}
 
    low.insert(v[0]);
    sLow += v[0];
    F(1,k,i){ins(v[i]);}
 
    cout<<sUp-sLow+med()<<" ";
 
    F(k,n,i){
        int left = (i-k);
        if(k==1){
            ins(v[i]);
            er(v[left]);
        }
        else{
            er(v[left]);
            ins(v[i]);
        }
        cout<<sUp-sLow+med()<<" ";
    }
    
 
}
 
