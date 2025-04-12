#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[1003];
int a[1003];

vector<int> dfs(int x, int fa) {
    vector<vector<int>> res;
    for (auto &v : g[x]) {
        if (v == fa) {
            continue;
        }
        res.push_back(dfs(v, x));
    }
    if (res.size() == 0) {
        return vector<int>{a[x], 0};
    }
    vector<int> dp(a[x] + 1);
    dp[0] = 1;
    for (int i = 0; i < res.size(); i++) {
        vector<int> tp = dp;
        for (int j = 0; j < res[i].size(); j++) {
            for (int k = a[x]; k >= res[i][j]; k--) {
                if (tp[k - res[i][j]]) {
                    dp[k] = 1;
                }
            }
        }
    }
    vector<int> ans;
    for (int i = a[x]; i >= 1; i--) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }
    ans.push_back(0);
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> ans = dfs(1, 0);
    cout << ans[0];

    return 0;
}