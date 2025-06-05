#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        if (a[x][y] > w) {
            a[x][y] = w;
            a[y][x] = w;
        }
    }

    for (int i = 1; i <= n; i++)
        a[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " \n"[j == n];

    return 0;
}