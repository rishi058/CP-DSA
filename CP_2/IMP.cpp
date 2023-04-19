#include <bits/stdc++.h>
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
using namespace std;
// using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define ll long long
#define ld long double
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define lb lower_bound
#define ub upper_bound
#define all1(v) (v).begin() + 1, (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define allr1(v) (v).rbegin() + 1, (v).rend()
#define pl pair<ll, ll>
#define vl vector<ll>
#define mkp make_pair // like v[i]=mp(1,3);
#define N 100002
#define inf 1e18
#define YES cout << "YES"
#define NO cout << "NO"
#define nl "\n"
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (av).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define sep(i, a, b) for (int i = a; i >= b; i--)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define hsb __lg
// hsb returns highest set bit of x
#define ctz __builtin_ctz
#define clz __builtin_clz
#define ffs __builtin_ffs
#define par __builtin_parity
#define parll __builtin_parityl
// use v.assign(size,val) instead of v.resize(size,val)
// strstr(s1,s2) return a string from where first occurence of s2 in //s1 occurs note strstr takes char array as input not string
// s.c_str to convert string to char array

// cpp template made by me and help taken from ishaan_15 and demoralizer template

// 1LL<<i imp!!!
// cout<<fixed<<setprecision(6)<<ans<<endl;

// sqrtl and floorl for ll

const int32_t mod = 1e9 + 7;

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.fr >> a.sc;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.fr << " " << a.sc;
    return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

ll inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll ceil_div(ll a, ll b) { return a % b == 0 ? a / b : a / b + 1; }
ll pwr(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void boost()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll C[1001][1001];

void nCr()
{
    C[0][0] = 1;
    C[1][0] = 1;
    C[1][1] = 1;

    for (ll i = 1; i < 1000; i++)
    {
        C[i + 1][i + 1] = 1;
        C[i + 1][0] = 1;
        for (ll j = 1; j <= i; j++)
        {
            C[i + 1][j] = mod_add(C[i][j], C[i][j - 1]);
        }
    }
}

// snippets: dsu,grundy,trie,segment,matrix enter daba ab nahi code //lane ke liye matrix for matrix exponentiation

// cant count good, then count the bad "atleast" ya "atmost" mei
// lagta ye

// PIR(Principle of Reversability): If all cases have the same ending
// forcefully notice things in  backward order

// x= k * (p1^a) * (p2^b)* ...
// think in primes to meet cndtn

// in subarray xor questions p=preXor[i]*desired_xor here p is //henceforth previously occurring xor in prefixxor arr mntn a
// cnt arr then ref(cf) even_subarrays

// interactive gcd: take i,j,x compare gcd(i,x) gcd(j,x) eliminate i //or j //(whosoever eliminated replace with x)

// lexicographic: left se start kia to sabse chotta assign karte //aage chalo
// right se try karo to just chota assign karte hue piche jao
// sari values jaha par bhi aa rahi hai unka index table banalo
// desc order mei aur lelo agar (sabse chotta) given (index perfect)

// prefix arr mei agr a[i]=a[i]+x kara to ye kaho ki pref[i..n] ko x
// se increase kardiya ya aise kehlo ki pref[0..i-1] ko x se
// dec kardiya ulta bhi socho ref(least prefix sum codeforces)

// greedy:to find minimum ops, find the maximum length possible of elements
// on which u are not performing that op

// every pmtn is a grp of directed disjoint cycles if edge (i,a[i])
// number of swaps to sort a pmtn=(n-c) (c:no. of cycles)

// in a cycle of size s exactly (s-1) ops are req to place them in //correct pos(i.e //a[i]==i)  //(ref Q: XORSort icpc prelims //amrita2022)

// count the no. of cases with that particular cnt

// dp ke question mei O(n2) optimise ho jata hai O(n) mei

// agar ye hi dekhna hai ki x1 se x2 filled or not use set called //freeRows

// agar ajeb combo like (factorial and 2powers) use "mask"
// to make a subset of all factorials and 2 powers for
// compensation

// na greedy na dp to binarysearch
// NOTE: binary search mei checkmid fun socho greedily fatafat

// big_palindrome= same + small_palindrome +same
// so if u have to take out largest palindrome from string s
// just find largest prefix=suffix using 2 pointers
// and apply kmp on remaining string and on reverse(rem_string)
// note:ek string mei at max 26 diff chars hi ho sakte hai
// ref:equal frequencies cf

// dp se to hoga par samajh nahi aa raha kaise matlab memoization

// bitmask bahut bada ho to 2pointer lagao left=0,right=0;
// jab tak valid mask left++ else loop break and right++
// ref QuizMaster(cf)

// mexQs ke liye multiset leke extra wale dal do iss st mei ref//(MEXANDINCREMENTS CF)

// AP mei aise karke bhi commdiff same cndn check ho sakti
//(a[k]-a[j])*(k-i)==(a[k]-a[i])*(k-j)

// agar yes ya no check karna hota to ye bhi imp cndn
// ki jaise agar var sum ko bhi p se divide karna pad raha ans
// nikalne ke liye then if (sum%p!=0) NO ho jata by default

// jab aisa ho ki maanlo tumne ek index ko nahi lia to
// kuch ho raha hai jo aage wali cheezo ko bhi affect kar raha hai
// to cheeze ek ek karke aaram se lo pehle 1st ki wajah se kya
// exact change aaya wo likho fir second ki wajah se...so on till kth
// pattern ban jata hai aise
// cases mei ref(Traps cf)

// subsequences k ho aise jinka xor x ho
// note agar k even hai so xor of all elements in arr==0
// else agar k==odd xor(all_in_arr)==x
// note: 2 subsequences with same xor ka xor=0 and 3 subsequences //with xor x ka xor=x so we can combine subsequences
// subsequence hi banane hai to max 2 size ke banao
//{i,i^x} type ya {x} type ref(HarmonizationOfXOR cf)

// path follow pattern srch ques trie ya set se hote//(ref:FixedPrefixPermutations cf)

// rotating an arr to get another arr uses 2 pointers i for a
// and j for arr b and if a[i]!=b[j] just store a[i] in multiset
// for later use of a[i] and i++ to further match things ref//(cyclicRotation cf)

// to maximise ans do ans+something and to maximise something
// as something=pre[i]-pre[j] for all 1<=j<i so take j with min pre //value while iterating as in to maximise a-b maximise a and //minimise b ref(https://www.hackerrank.com/contests/gdsc-cp-recruitment/challenges/flip-flip-1)

// agr koi soln O(n2 ya n3) se kam mei na aa raha ho dimaag mei to ye
// socho ki andar wale loop ko kya pata n baar chalne ki need na ho
// wo max 99 ya 26 ya 26*26 etc bar hi chalne ki need ho

// sare ops karne ke baad let a be a' and b be b' or let a become
//(a+x) and b become (b+y) aisa karke ek proper function banao
// and then minimise the "varying" part ofd that fun. by bitmasking
// jaise jaha par b ka bit nonset waha par b' set kar diya to
// b' by default>=b ho jata so aage ke sare 0 manke check and jaha //par b set waha b' ka bit set for b'>=b ref(strange test cf)

// dp mein aisa bhi hota hain ki agar cpu1 aur cpu2 hai and
// new item ya to cpu1 mei jayegi ya cpu2 then we can also say
// a[item+1] aur a[item] ya to same cpu mein hoge ya different cpu
//(ref Hot Start Up cf)

// kuch na samajh aaye to O(n2) ya O(n3) ya O(n4) ka brute force
// to run karke dekh hi lia karo aur jaise hi cndn mile
// break kar jao pigeonhole principle se socha karo(ref c8kbf codechef)

// agar har dp[i-1][j] se dp[i][j] mei x add hora hai
// i.e dp[i][j]=dp[i-1][j]+some const to ye dp segment_tree dp
// mei cnvrtible ho jati hai ref(hot startup cf)

// ek 5 multiply karne se accha to mai 2 bar 2 multiply kardu
//(ref: maximum set cf)

// t==0: before the segment t==1: inside the segment t==2: after //the segment dp[i][j][t] i:no.of elements considered till now
// j:no. of elements in segment(0<=j<=k) t:state
// dp[i+1][jj][tt]=max(this_itself,dp[i][j][t]+(tt==1)?add:0)
// t<=tt<=3 ref(maximum subarray edu 144 cf)

// mmi of a exist for mod m iff a and m are coprime

// note:(x^(pow(2,i)+x)==2^i)
// based on above: a 256*256 matrix like:
// 0 1 2 3 ...255
// 256........511
// 512........(512+255)
//(512+256)....(512+256+255)
// iss mat ke sare 2*2 sub-matrix ka xor 0 hoga (ref:very beautiful //blankets cf round857)

// segment_tree+dp ref(music festival round 857)

// proper formula banake variable two ko minimize ya maximise karde
// ref(accomodation cf nebius welcome round)

// if u want to split and merge a lot of arrs to make final arr asc
// can first just continue the splitting with no merging i.e.
// split at i when a[i]>a[i+1] for all the arrays
// now start the merging and use huffman coding and priorityQ to //merge ref(Break,merge and sort icpc amrita prelim 2020)

// tree is a simplest bipartite graph

// subset S from a graph s.t. sz(S) <= p and for every vertex u in //the graph, there exists a vertex v in S such that dist(u,v) <= p
// use euler tree ref(central subset amrita icpc prelims 2023)

// agr graph ya tree queries ke q mei tle aaye then ignore all the //levels i where (no. of nodes on ith level)>sqrt(n)
// ref(tree Master cf 858 prob e)

// in lexicographic min questions with both increment and decrement
// allowed always try to preserve the number of decrements
// also to make char c reach 'a' u can either increase or decrease
// and since up+down==26 always so to preserve down first kill all
// the ones with least value of ups(same as more value of downs)
// use priority_q for this (ref codechefstarters83 ROTMIN)

void solve()
{
    // read the question again "CAREFULLY" if u are getting
    // repetitive wrong answers

    ll n, m;
    cin >> n >> m;

    vector<vl> a(n + 1, vl(m + 1));

    rep(i, 1, n + 1)
    {
        rep(j, 1, m + 1)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    rep(i, 1, m + 1)
    {
        vl v;
        v.pb(0);
        rep(j, 1, n + 1)
        {
            v.pb(a[j][i]);
        }

        sort(all(v));
        // for(auto p:v){
        //     cout<<p<<" ";
        // }

        // cout<<endl;
        vl pref(n + 1, 0);

        rep(j, 1, n + 1)
        {
            pref[j] = pref[j - 1] + v[j];
        }
        rep(j, 1, n + 1)
        {
           ll p= ((pref[n] - pref[j]) - (v[j] * (n - j)));
        //    cout<<i<<" "<<j<<" "<<p<<endl;
            ans+=p;
        }
    }
    cout << ans << endl;
}

int main()
{
    // your code goes here
    boost();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int t = 1;
    cin >> t;
    // comment above out when no test cases

    while (t--)
    {
        solve();
    }
    return 0;
}
