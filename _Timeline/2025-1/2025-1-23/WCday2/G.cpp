#include <bits/stdc++.h>
#define int long long
using namespace std;

int ksm(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m == 1)
    {
        cout << 1 << '\n';
        return;
    }
    int ans = 1;
    int la = abs(n - m);
    while (1)
    {
        ans++;
        if (abs(ksm(m, ans) - n) >= la)
        {
            cout << ans - 1 << '\n';
            return;
        }
        la = abs(ksm(m, ans) - n);
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