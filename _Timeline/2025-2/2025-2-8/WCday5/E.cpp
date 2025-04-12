#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n = 3;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    int cntG = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'G')
                cntG++;
        }
    }
    if (cntG == 9)
    {
        cout << "Yes\n";
        return;
    }

    auto c = [&](int i1, int j1, int i2, int j2) -> bool
    {
        return a[i1][j1] != 'O' && a[i2][j2] != 'O';
    };

    int ok = 0;

    if (c(1, 1, 1, 1) && c(1, 2, 1, 3) && c(2, 1, 3, 1) ||
        c(1, 3, 1, 3) && c(1, 1, 1, 2) && c(2, 3, 3, 3) ||
        c(3, 1, 3, 1) && c(1, 1, 2, 1) && c(3, 2, 3, 3) ||
        c(3, 3, 3, 3) && c(1, 3, 2, 3) && c(3, 1, 3, 2))
        ok = 1;

    if (a[1][1] == 'X')
    {
        ok |= c(1, 2, 1, 3);
        ok |= c(2, 1, 3, 1);
        ok |= c(2, 2, 3, 3);
    }
    if (a[1][2] == 'X')
    {
        ok |= c(1, 1, 1, 3);
        ok |= c(2, 2, 3, 2);
    }
    if (a[1][3] == 'X')
    {
        ok |= c(1, 1, 1, 2);
        ok |= c(2, 3, 3, 3);
        ok |= c(2, 2, 3, 1);
    }
    if (a[2][1] == 'X')
    {
        ok |= c(1, 1, 3, 1);
        ok |= c(2, 2, 2, 3);
    }
    if (a[2][2] == 'X')
    {
        ok |= c(1, 1, 3, 3);
        ok |= c(1, 3, 3, 1);
        ok |= c(2, 1, 2, 3);
        ok |= c(1, 2, 3, 2);
    }
    if (a[2][3] == 'X')
    {
        ok |= c(2, 1, 2, 2);
        ok |= c(1, 3, 3, 3);
    }
    if (a[3][1] == 'X')
    {
        ok |= c(1, 1, 2, 1);
        ok |= c(3, 2, 3, 3);
        ok |= c(2, 2, 1, 3);
    }
    if (a[3][2] == 'X')
    {
        ok |= c(3, 1, 3, 3);
        ok |= c(1, 2, 2, 2);
    }
    if (a[3][3] == 'X')
    {
        ok |= c(1, 1, 2, 2);
        ok |= c(1, 3, 2, 3);
        ok |= c(3, 1, 3, 2);
    }
    cout << (ok ? "Yes" : "No") << '\n';
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