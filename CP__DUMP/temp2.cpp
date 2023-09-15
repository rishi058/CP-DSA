#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

ll tt;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tt;
    while(tt--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n ;i++)cin >> a[i];
        string s;
        cin >> s;

        int len = (int)sqrt(n + .0)+1;
        vector<int> xor1(len);
        vector<int> xor0(len);

        for (int i=0; i<n; ++i)
        {
        if(s[i] == '0')
        xor0[i / len] ^= a[i];
        else
        xor1[i / len] ^= a[i];
        }
        ll q;
        cin >> q;
        while(q--){
        ll x;
        cin >> x;
        if(x == 1)
        {
        int l, r;
        cin >> l >> r;
        l--;r--;
        for (int i=l; i<=r;)
        if (i % len == 0 && i + len - 1 <= r) {
            // if the whole block starting at i belongs to [l, r]
//            sum += b[i / len];
            swap(xor0[i/len] , xor1[i/len]);
            i += len;
        }
        else {
            xor0[i/n] ^= a[i];
            xor1[i/n] ^= a[i];
            ++i;
        }


        }
        else
        {
        ll tmp;
        cin >> tmp;
        ll ans = 0;
        if(tmp == 0)
        for(int i = 0 ; i < len ; i++)
            ans ^= xor0[i];
        else
        for(int i = 0 ; i < len ; i++)
            ans ^= xor1[i];
        cout << ans << ' ';
        }


        }
        cout << endl;
    }
}