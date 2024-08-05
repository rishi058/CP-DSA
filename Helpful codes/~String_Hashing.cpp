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
You are given a string that consists of n characters between a—z. The positions of the string
are indexed 1, 2, ... , n.
Your task is to process m operations of the following types:
1. Change the character at position k to c
2. Check if the substring from position a to position b is a palindrome
*/

/*
Approach :-
String Hashing combined with Segment Tree Approach :-
 
STRING_HASHING (ROLLING HASH FUNCTION):-
BASE should be >=28 always ;
Take mod = 1e9+7 for preventing int overflow ;
 
Example :- "cde" = [3*(28)^0 + 4*(28)^1 + 5*(28)^2] = ...   

! NOTE :- TRY to start exponent from 1 to avoid edge cases i.e  "cde" = [3*(28)^1 + 4*(28)^2 + 5*(28)^3] 
! Use 2 hash with 2 dif base & mod to avoid collision, two string are equal if both hashesare equal
 
Imp Property :-  hash->str[i..j] = 1/(base^i) * { hash->str[0..j] - hash->str[0..(i-1)] };
 
E.g :- hash["na"] = [1/(28)^2] * [ hash["apna"] - hash["ap"] ] ;
 
1/(base^i) =>  i = (extra + 1) {extra = len(required)-len(whole_prefix) str}
 
*/
 
 
/*
Approach 4 this question ->
we will create 2 hash array(1 prefix & 1 suffix)
 
*/
 
const int base = 28;
 
int power(int x, int y){
    int res = 1; 
    x = x % mod; 
    while (y){
        if (y & 1){res = (res * x) % mod;}
        y >>= 1; 
        x = (x * x) % mod;
    }
    return res;
}
 
class segment{
public:
	vector<int> tree;
	int n ;
 
	segment(){}
	segment(vector<int>&arr){build(arr);}
 
	void build(vector<int>&arr){
		n = arr.size();
		tree.resize(2*n, 0);
 
		for(int i=0; i<n; i++){tree[n+i]=arr[i];}
 
		for(int i=(n-1); i>0; --i){
			tree[i] = ( tree[i<<1] + tree[i<<1 | 1] ) % mod;	
		}
	}
 
	// 0 based indexing.
	void updateTreeNode(int p, int value){
		tree[p+n] = value;
		p = p+n;
		for(int i=p; i > 1; i >>= 1){
			tree[i>>1] = (tree[i] + tree[i^1]) % mod;
		}
	}
 
	int query(int l, int r){  // both inclusive
		r++;
		if(l==r){return tree[r+n-1];}
		int res = 0;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l&1){res = (tree[l++] + res) % mod;}
			if(r&1){res = (tree[--r] + res) % mod;}
		}
		return res;
	}
 
};
 
int32_t main()
{
    RISHI
    int T = 1;
    while(T--)
    {
        int n, q;
        cin>>n>>q;
 
        string str; cin>>str;
        vi tempPre(n), tempSuff(n);
 
        for(int i=0; i<n; i++){
            tempPre[i] = ( power(base, i)*(str[i]-'a'+1) ) % mod;
            tempSuff[i] = ( power(base, n-i-1)*(str[i]-'a'+1) ) % mod;
        }
 
        segment prefixHash(tempPre);
        segment suffixHash(tempSuff);
 
        // cout<<prefixHash.tree.size()<<" ";
        // print(prefixHash.tree);
        // print(suffixHash.tree);
 
        while(q--)
        {
            int type; cin>>type;
 
            if(type==1){
                int pos; char x;
                cin>>pos>>x;
 
                pos--;
                int new_pre_hash = (power(base, pos)*(x-'a'+1))%mod;
                prefixHash.updateTreeNode(pos, new_pre_hash);
 
                int new_suff_hash = (power(base, n-pos-1)*(x-'a'+1))%mod;
                suffixHash.updateTreeNode(pos, new_suff_hash);
            }   
            else{
                int l,r;
                cin>>l>>r;
                l--; r--;
 
                int hash1 = (prefixHash.query(l,r)*(power(base,n-r-1))) % mod;  // n-r-1 represents how many more elements suffix array cover 
                int hash2 = (suffixHash.query(l,r)*(power(base,l))) % mod;
                // cout<<hash1<<" "<<hash2<<"\n";
                if(hash1==hash2){cout<<"YES\n";}
                else{cout<<"NO\n";}
            }
        }
 
    }
 
}
