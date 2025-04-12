#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    map<int, vector<int>> mp;
    map<int, int> cnt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] >> 2;
        b[i] <<= 2;
        cnt[b[i]]++;
        mp[b[i]].push_back(a[i]);
    }
    for (auto &[f, v] : mp)
        sort(v.begin(), v.end(), greater<>());

    for (int i = 1; i <= n; i++)
    {
        cout << mp[b[i]][--cnt[b[i]]] << ' ';
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