struct SparseTable {
    int mx[maxn][25], lg[maxn];
    int n, a[maxn];

    void build() {
        lg[0] = -1;
        for (int i = 1; i <= n; i++) {
            mx[i][0] = a[i];
            lg[i] = lg[i / 2] + 1;
        }
        for (int i = 1; i <= lg[n]; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[j][i] = max(mx[j][i - 1], mx[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int query(int l, int r) {
        int len = lg[r - l + 1];
        return max(mx[l][len], mx[r - (1 << len) + 1][len]);
    }
} ST;