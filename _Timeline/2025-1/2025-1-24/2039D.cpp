#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> S(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> S[i];
    }
    sort(S.begin() + 1, S.end(), greater<>());

    vector<int> a(n + 1);
    a[1] = S[1];
    for (int i = 1; i <= n; i++)
    {
        auto it = upper_bound(S.begin() + 1, S.end(), a[i], greater<>());
        if (it == S.end() && i + i <= n)
        {
            cout << -1 << '\n';
            return;
        }
        if (it == S.end())
            continue;
        int num = *it;
        for (int j = i + i; j <= n; j += i)
        {
            a[j] = num;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
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