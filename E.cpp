#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n, m;
int zi, mu;
int vis[11];

void dfs(int x) {
    if (x == n) {
        mu++;
        if (!vis[n]) {
            zi++;
        }
    }
    if (x <= m) {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                dfs(x + 1);
                vis[i] = 0;
            }
        }
    } else {
        if (!vis[x]) {
            vis[x] = 1;
            dfs(x + 1);
            vis[x] = 0;
        } else {
            for (int i = 1; i <= n; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    dfs(x + 1);
                    vis[i] = 0;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    dfs(1);

    cout << fixed << setprecision(10);
    cout << 1.0 * zi / mu << '\n';

    return 0;
}