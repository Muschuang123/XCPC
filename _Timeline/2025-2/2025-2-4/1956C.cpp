#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    i64 s = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s += max(i, j);
        }
    }
    cout << s << ' ' << 2 * n << '\n';
    for (int i = 1; i <= 2 * n; i++)
    {
        int op = i % 2 ? 1 : 2;
        cout << op << ' ' << (i + 1) / 2 << ' ';
        for (int j = n; j >= 1; j--)
        {
            cout << j << " \n"[j == 1];
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}