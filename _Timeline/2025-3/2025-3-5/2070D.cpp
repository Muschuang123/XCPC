#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

// vector<int> d[300005];

void solve()
{
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     d[i].clear();
    // }
    vector<int> de(n + 1), fa(n + 1);
    vector<i64> v(n + 1), vd(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        de[i] = de[fa[i]] + 1;
        // d[de[i]].push_back(i);
    }

    vector<int> ver(n + 1);
    for (int i = 1; i <= n; i++) ver[i] = i;
    auto cmp = [&](const int &a, const int &b)
    {
        return de[a] < de[b];
    };
    sort(ver.begin() + 1, ver.end(), cmp);

    vd[0] = 1;
    for (int o = 2; o <= n; o++)
    {
        int &i = ver[o];
        v[i] = (vd[de[i] - 1] - v[fa[i]] + mod) % mod;
        vd[de[i]] = (vd[de[i]] + v[i]) % mod;
    }

    i64 ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans = (ans + v[i]) % mod;
    }
    cout << ans << '\n';
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