const ld eps = 1e-8L;

// gauss(a, n).empty() : no solution
vector<ld> gauss(vector<vector<ld>> a, int n) {
    vector<ld> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int fz = 0;
        for (int k = i; k <= n; k++) {
            if (fabsl(a[k][i]) > eps) {
                fz = k;
                break;
            }
        }
        if (fz != i) {
            swap(a[fz], a[i]);
        }
        if (fabsl(a[i][i]) < eps) {
            return {};
        }
        for (int j = n + 1; j >= i; j--) {
            a[i][j] /= a[i][i];
        }
        for (int k = i + 1; k <= n; k++) {
            for (int j = n + 1; j >= i; j--) {
                a[k][j] -= a[k][i] * a[i][j];
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = a[i][n + 1];
    }
    return ans;
}