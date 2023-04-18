#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
	
struct Fenwick{
	vector<ll> arr;
	int n;
	Fenwick(int N, int C) : n(N){
		arr.assign(N,0);
		add(0,C);
	}
	ll get(int pos){
		ll val = 0;
		while(pos>=0){
			val+=arr[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return val;
	}
	void add(int pos, ll val){
		while(pos<n){
			arr[pos] += val;
			pos = (pos | (pos + 1));
		}
	}
	void update(int x, int y, ll val){
		add(x, val);
		add(y+1, -val);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,M,C;
	cin>>N>>M>>C;

	N++;

	Fenwick fen(N,C);
	
	while(M--){
		char temp;
		cin>>temp;
		if(temp=='Q'){
			int pos;
			cin>>pos;
			cout<<fen.get(pos)<<"\n";
		}
		else {
			int x,y,c;
			cin>>x>>y>>c;
			fen.update(x,y,c);
		}
	}
}