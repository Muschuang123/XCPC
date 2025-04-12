#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 在非严格单调递增的序列上进行+1操作，
 * 每次只加相等数的最右边那个数，
 * 可以保证持久单调
 */

const int mod = 998244353;

int ksm(int a, int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> sa = a, sb = b;
    sort(sa.begin() + 1, sa.end());
    sort(sb.begin() + 1, sb.end());

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * min(sa[i], sb[i]) % mod;
    }
    cout << ans << ' ';

    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            int ind = --upper_bound(sa.begin() + 1, sa.end(), a[x]) - sa.begin();
            a[x]++;
            if (sa[ind] < sb[ind])
            {
                ans = ans * ksm(sa[ind], mod - 2) % mod;
                sa[ind]++;
                ans = ans * sa[ind] % mod;
            }
            else
            {
                sa[ind]++;
            }
        }
        else
        {
            int ind = --upper_bound(sb.begin() + 1, sb.end(), b[x]) - sb.begin();
            b[x]++;
            if (sb[ind] < sa[ind])
            {
                ans = ans * ksm(sb[ind], mod - 2) % mod;
                sb[ind]++;
                ans = ans * sb[ind] % mod;
            }
            else
            {
                sb[ind]++;
            }
        }
        cout << ans << ' ';
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