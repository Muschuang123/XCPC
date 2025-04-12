#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(2 * n + 1), pre(2 * n + 1), suf(2 * n + 2);
    set<i64> ss;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        ss.insert(a[i]);
    }
    sort(a.begin() + 1, a.end(), greater<>());
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i != 1 && i % 2)
            a[i] = -a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 2 * n; i >= 1; i--)
    {
        suf[i] = suf[i + 1] - a[i];
    }
    a[1] = -a[1];
    i64 sum = -accumulate(a.begin() + 1, a.end(), 0LL);
    for (int i = 1; i <= 2 * n; i++)
    {
        if (i % 2)
            a[i] = -a[i];
    }

    if (abs(sum) <= (i64)1e18 && !ss.count(sum))
    {
        cout << sum << ' ';
        for (int i = 1; i <= 2 * n; i++)
        {
            cout << a[i] << " \n"[i == 2 * n];
        }
        return;
    }

    for (int i = 1; i <= 2 * n; i++)
    {
        if (abs(pre[i] - suf[i + 1]) <= (i64)1e18 && !ss.count(pre[i] - suf[i + 1]))
        {
            for (int j = 1; j <= i; j++)
            {
                cout << a[j] << ' ';
            }
            cout << pre[i] - suf[i + 1];
            for (int j = i + 1; j <= 2 * n; j++)
            {
                cout << ' ' << a[j];
            }
            cout << '\n';
            return;
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