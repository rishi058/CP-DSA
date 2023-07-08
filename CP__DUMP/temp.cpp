/*
void solve() {
    ll n, sum = 0;
    get(n);

    vi arr(n);
    rep0(i, n) {
       get(arr[i]);
       sum += arr[i];
    }

    if(sum%2) {
       put("NO");
       return;
    }

    vi diff;
    rep1(i, n-1) {
       diff.pb(arr[i-1] - arr[i]);
    }


    rep1(i, n-2) {
          int a = abs(diff[i-1]);
          int b = abs(diff[i]);
          int d = abs(a - b);

          if(d > 1) {
              put("NO");
              return;
          }
    }

    put("YES");
}
*/