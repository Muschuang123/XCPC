struct SparseTable {
    int mx[maxn][25], lg[maxn];

    void build(int n, vector<int> &a) {
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

// ---------------------------------------
// dynamic size version:

// 1-index
struct SparseTable {
    vector<vector<int>> mx;
    vector<int> a, lg;
    int n;

    // void assign(int _n) {
    SparseTable(int _n) {
        n = _n;
        a.assign(n + 1, 0);
        mx.assign(n + 1, vector<int>(__lg(n) + 2, 0));
        lg.assign(n + 1, 0);
    }

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
};