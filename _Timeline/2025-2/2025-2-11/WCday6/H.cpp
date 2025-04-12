#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int l, r, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r >> c;
    }
    if (r - l & 1)
    {
        for (int i = n; i >= 1; i--)
        {
            cout << i << " \n"[i == 1];
        }
    }
    else
    {
        if (n & 1)
        {
            cout << n << ' ';
            for (int i = n - 1; i >= 1; i--)
            {
                if (i & 1)
                {
                    cout << i + 1 << ' ';
                }
                else
                {
                    cout << i - 1 << ' ';
                }
                
            }
        }
        else
        {
            for (int i = n; i >= 1; i--)
            {
                if (i & 1)
                {
                    cout << i + 1 << ' ';
                }
                else
                {
                    cout << i - 1 << ' ';
                }
                
            }
        }
        cout << '\n';
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