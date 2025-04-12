#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 利用奇偶性均分输赢。
 */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    if (n % 2)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cout << (i - j & 1 ? "1 " : "-1 ");
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (i % 2 && j == i + 1)
                {
                    cout << "0 ";
                    continue;
                }
                cout << (i - j & 1 ? "1 " : "-1 ");
            }
        }
    }

    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}