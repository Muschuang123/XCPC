#include <bits/stdc++.h>
// #define int long long
using namespace std;

/**
 * 能填就填，填不了完蛋。
 * 不完蛋的基础上：
 * 出现四个点组成一个正方形，就可以多解。
 */

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> a(3, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) cin >> a[1][i];
    for (int i = 1; i <= n; i++) cin >> a[2][i];

    int no = 0, mul = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[1][i] == '#' && a[2][i] == '#')
            continue;

        if (a[1][i] == '.' && a[2][i] == '.')
        {
            if (i < n && a[1][i + 1] == '.' && a[2][i + 1] == '.')
                mul = 1;
            a[1][i] = a[2][i] = '#';
        }
        else if (a[1][i] == '.')
        {
            if (i < n && a[1][i + 1] == '.')
                a[1][i] = a[1][i + 1] = '#';
            else 
                no = 1;
        }
        else
        {
            if (i < n && a[2][i + 1] == '.')
                a[2][i] = a[2][i + 1] = '#';
            else 
                no = 1;
        }
        
    }

    if (no)
    {
        cout << "None\n";
    }
    else if (mul)
    {
        cout << "Multiple\n";
    }
    else
    {
        cout << "Unique\n";
    }

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