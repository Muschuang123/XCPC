#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    int q;
    cin >> q;
    while (q--)
    {
        int l, u;
        cin >> l >> u;
        int idx = --upper_bound(a.begin() + l + 1, a.end(), a[l - 1] + u) - a.begin();
        if (idx + 1 <= n)
        {
            if (u - (a[idx] - a[l - 1]) <= (a[idx + 1] - a[l - 1]) - u - 1)
            {
                cout << idx << ' ';
            }
            else
            {
                cout << idx + 1 << ' ';
            }
        }
        else
        {
            cout << idx << ' ';
        }
    }
    cout << '\n';
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