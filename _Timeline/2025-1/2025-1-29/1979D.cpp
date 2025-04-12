#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    int cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
            cnt1++;
    }

    if (cnt1 % k != 0 || (n - cnt1) % k != 0)
    {
        cout << -1 << '\n';
        return;
    }

    int cnt = 0;
    vector<int> b(n + 1);
    vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        cnt++;
        if (i == n || s[i] != s[i + 1])
        {
            b[i] = cnt;
            if (cnt != k)
                v.push_back(i);
            cnt = 0;
        }
    }

    int p = 0;

    if (v.size() == 0)
    {
        p = n;
    }
    if (v.size() > 2)
    {
        cout << -1 << '\n';
        return;
    }
    if (v.size() == 1)
    {
        p = v[0] - k;
    }
    if (v.size() == 2)
    {
        if (b[v[0]] + b[v[1]] == k)
        {
            p = v[0];
        }
        else
        {
            p = v[0] - k;
        }
    }

    if (p < 0)
    {
        cout << -1 << '\n';
        return;
    }

    reverse(s.begin() + p + 1, s.end());

    for (int i = 1; i <= k; i++)
    {
        if (s[i] != s[1])
        {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n - k; i++)
    {
        if (s[i] == s[i + k])
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << p << '\n';
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