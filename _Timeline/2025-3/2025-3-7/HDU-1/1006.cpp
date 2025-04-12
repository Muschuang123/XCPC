#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> u(n + 1), v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }
    map<i64, int> mp;
    for (int i = 1; i <= n; i++)
    {
        set<i64> ss;
        if ((w[i] - v[i]) % u[i] == 0)
        {
            i64 t = (w[i] - v[i]) / u[i];
            if (!ss.count(t)) mp[t]++, ss.insert(t);
            if (!ss.count(-t)) mp[-t]++, ss.insert(-t);
        }
        if ((u[i] - w[i]) % v[i] == 0)
        {
            i64 t = (u[i] - w[i]) / v[i];
            if (!ss.count(t)) mp[t]++, ss.insert(t);
            if (!ss.count(-t)) mp[-t]++, ss.insert(-t);
        }
        if ((v[i] - u[i]) % w[i] == 0)
        {
            i64 t = (v[i] - u[i]) / w[i];
            if (!ss.count(t)) mp[t]++, ss.insert(t);
            if (!ss.count(-t)) mp[-t]++, ss.insert(-t);
        }
    }

    for (auto &[f, s] : mp)
    {
        if (s == n && f >= 0)
        {
            cout << f << '\n';
            return;
        }
    }
    cout << "";
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