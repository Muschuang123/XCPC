#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 不要忘了本来就有可能是 0 的情况。

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<i64> a(n + 2);
    vector<pair<int, int>> q(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        q[i].first = l, q[i].second = r;
        a[l]++, a[r + 1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    i64 cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i] == 0;
        a[i] = a[i] == 1;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        cout << cnt + a[q[i].second] - a[q[i].first - 1] << '\n';
    }

    return 0;
}