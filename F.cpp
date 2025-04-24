#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];

int ans = 0;

void dfs(int x, int fa) {
    if (g[x].empty()) {
        return;
    }
    ans += (int)g[x].size() - 1;
    for (auto &v : g[x]) {
        if (v == fa) {
            continue;
        }
        dfs(v, x);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 0);

    cout << ans << '\n';


    return 0;
}