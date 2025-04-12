#include <bits/stdc++.h>
using i64 = long long;
#define int long long
using namespace std;

bool cmp(const array<int, 3> &a, const array<int, 3> &b)
{
    return a[2] > b[2] || a[2] == b[2] && a[0] > b[0] || a[2] == b[2] &&  a[0] == b[0] && a[1] < b[1];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<double> a(n + 1);
    vector<int> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int n;
            int p;
            cin >> n >> p;
            a[i] -= p;
            a[n] += p;
            g[n]++;
        }
    }

    vector<array<int, 3>> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[i][0] = g[i];
        ans[i][1] = i;
        ans[i][2] = a[i];
    }

    sort(ans.begin() + 1, ans.end(), cmp);
    cout << fixed << setprecision(2);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i][1] << ' ' << double(ans[i][2]) / 100 << '\n';
    }

    return 0;
}