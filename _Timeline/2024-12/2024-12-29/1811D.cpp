#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> F(51);

void init()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 50; i++)
        F[i] = F[i - 1] + F[i - 2];
}

bool dfs(int n, int x, int y)
{
    int h = F[n], w = F[n + 1];
    if (x > h || y > w)
        return 0;
    int flx = x == 1 || x == h, fly = y == 1 || y == w;

    if (y > h)
        y -= h;
    if (flx && fly)
        return 1;
    else 
        return dfs(n - 1, y, x);
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    cout << (dfs(n, x, y) ? "YES\n" : "NO\n");
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    init();

    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}