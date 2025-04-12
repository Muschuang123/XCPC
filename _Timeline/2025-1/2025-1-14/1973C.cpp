#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a;

void solve()
{
    cin >> n;
    a.clear();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> b(n + 1), c(n + 1);
    int bsc = 0, csc = 0;
    vector<pair<int, int>> f;

    // b
    for (int i = 2; i + 1 <= n; i += 2)
        f.push_back({a[i], i});
    sort(f.begin(), f.end());
    for (int i = 0; i < f.size(); i++)
    {
        b[f[i].second] = n - i;
    }
    f.clear();
    f.resize(0);

    for (int i = 1; i <= n; i++)
        if (b[i] == 0)
            f.push_back({a[i], i});
    sort(f.begin(), f.end(), greater<>());
    for (int i = 0; i < f.size(); i++)
    {
        b[f[i].second] = i + 1;
    }
    f.clear();
    f.resize(0);

    // c
    for (int i = 3; i + 1 <= n; i += 2)
        f.push_back({a[i], i});
    sort(f.begin(), f.end());
    for (int i = 0; i < f.size(); i++)
    {
        c[f[i].second] = n - i;
    }
    f.clear();
    f.resize(0);

    for (int i = 1; i <= n; i++)
        if (c[i] == 0)
            f.push_back({a[i], i});
    sort(f.begin(), f.end(), greater<>());
    for (int i = 0; i < f.size(); i++)
    {
        c[f[i].second] = i + 1;
    }
    f.clear();
    f.resize(0);

    for (int i = 2; i + 1 <= n; i++)
    {
        if (b[i] + a[i] > b[i - 1] + a[i - 1] && b[i] + a[i] > b[i + 1] + a[i + 1])
            bsc++;
        if (c[i] + a[i] > c[i - 1] + a[i - 1] && c[i] + a[i] > c[i + 1] + a[i + 1])
            csc++;
    }

    if (bsc > csc)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << b[i] << " \n"[i == n];
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << c[i] << " \n"[i == n];
        }
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