#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        i64 x;
        cin >> x;
        if (x % 2 == 0 || (i64)sqrtl(x) * (i64)sqrtl(x) == x)
        {
            a[i] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}