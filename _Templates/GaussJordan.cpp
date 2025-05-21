const ld eps = 1e-8L;

// vector<vector<ld>> a(n + 1, vector<ld(n + 2));
// gauss[0] < 0 : no solution
// gauss[0] > 0 : infinite solutions
vector<ld> gauss_jordan(vector<vector<ld>> a, int n) {
    vector<ld> ans(n + 1);
    // cur 是当前处理的列
    int cur = 1;
    // i 是 主元 列 序号
    for (int i = 1; i <= n; i++) {
        int fz = cur;
        for (int k = cur + 1; k <= n; k++) {
            if (fabsl(a[k][i]) > fabsl(a[fz][i])) {
                fz = k;
            }
        }
        if (fz != cur) {
            swap(a[fz], a[cur]);
        }
        // 如果没有 非 0 主元，那么保持 cur (当前处理的行)，处理下一列
        if (fabsl(a[cur][i]) < eps) {
            continue;
        }
        for (int k = 1; k <= n; k++) {
            if (k == cur) {
                continue;
            }
            ld t = a[k][i] / a[cur][i];
            for (int j = i; j <= n + 1; j++) {
                a[k][j] -= t * a[cur][j];
            }
        }
        cur++;
    }
    if (cur <= n) {
        while (cur <= n) {
            if (fabsl(a[cur][n + 1]) > eps) {
                ans[0] = -1;
                return ans;
            }
            cur++;
        }
        ans[0] = 1;
        return ans;
    }
    for (int i = 1; i <= n; i++) {
        ans[i] = a[i][n + 1] / a[i][i];
    }
    return ans;
}