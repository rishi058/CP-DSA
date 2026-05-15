class Main {
    public static long solve(long p, String a, String b) {
        int n = a.length();
        int m = b.length();
        long inf = (long) 1e18;
        
        long[][] dm = new long[n + 1][m + 1];
        long[][] da = new long[n + 1][m + 1];
        long[][] db = new long[n + 1][m + 1];
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dm[i][j] = da[i][j] = db[i][j] = inf;
            }
        }
        
        dm[0][0] = 0;
        for (int i = 1; i <= n; i++) da[i][0] = (long) i * i;
        for (int j = 1; j <= m; j++) db[0][j] = (long) j * j;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long c = (a.charAt(i - 1) == b.charAt(j - 1)) ? 0 : p;
                dm[i][j] = Math.min(Math.min(dm[i - 1][j - 1], da[i - 1][j - 1]), db[i - 1][j - 1]) + c;
                
                long ma = inf;
                for (int k = 1; k <= i; k++) {
                    ma = Math.min(ma, Math.min(dm[i - k][j], db[i - k][j]) + (long) k * k);
                }
                da[i][j] = ma;
                
                long mb = inf;
                for (int k = 1; k <= j; k++) {
                    mb = Math.min(mb, Math.min(dm[i][j - k], da[i][j - k]) + (long) k * k);
                }
                db[i][j] = mb;
            }
        }
        
        return Math.min(Math.min(dm[n][m], da[n][m]), db[n][m]);
    }

    public static void main(String[] args) {
        System.out.println(solve(5, "a", "b"));
        System.out.println(solve(1, "abc", "a"));
        System.out.println(solve(10000, "abc", "xyz"));
    }
}