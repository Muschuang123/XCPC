#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
        {
            c1 += s[i] == '1';
            c2 += t[i] == '1';
        }
        else
        {
            c1 += t[i] == '1';
            c2 += s[i] == '1';
        }
    }
    if (n % 2)
    {
        if (c1 <= n / 2 && c2 <= n / 2 + 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    else 
    {
        if (c1 <= n / 2 && c2 <= n / 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
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