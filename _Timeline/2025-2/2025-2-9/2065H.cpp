#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 998244353;

i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ans;
}

struct fenwick
{
    int n;
    vector<i64> t;

    fenwick(int _n = 0)
    {
        n = _n - 1;
        t.resize(n + 1);
    }

    int lowbit(int x)
    {
        return x & (-x);
    }

    void add(int index, i64 delta)
    {
        for (int i = index; i <= n; i += lowbit(i))
            t[i] = (t[i] + delta + mod) % mod;
    }

    i64 query(int index)
    {
        i64 ans = 0;
        for (int i = index; i > 0; i -= lowbit(i))
            ans = (ans + t[i]) % mod;
        return ans;
    }

    i64 query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    fenwick pre0(n + 1), pre1(n + 1), suf0(n + 1), suf1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre0.add(i, ksm(2, i - 1));
        suf0.add(i, ksm(2, n - i));
    }

    i64 ans = (ksm(2, n) - 1 + mod) % mod;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            ans = (ans + (pre0.query(1, i - 1)) + (suf0.query(i + 1, n)) + 2 * (pre0.query(1, i - 1)) * (suf0.query(i + 1, n))) % mod;
            ans = ((ans - (pre1.query(1, i - 1)) - (suf1.query(i + 1, n)) - 2 * (pre1.query(1, i - 1)) * (suf1.query(i + 1, n))) % mod + mod) % mod;
            
            pre0.add(i, -ksm(2, i - 1));
            suf0.add(i, -ksm(2, n - i));
            pre1.add(i, ksm(2, i - 1));
            suf1.add(i, ksm(2, n - i));
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int i;
        cin >> i;
        if (s[i] == '0')
        {
            ans = (ans + (pre0.query(1, i - 1)) + (suf0.query(i + 1, n)) + 2 * (pre0.query(1, i - 1)) * (suf0.query(i + 1, n))) % mod;
            ans = ((ans - (pre1.query(1, i - 1)) - (suf1.query(i + 1, n)) - 2 * (pre1.query(1, i - 1)) * (suf1.query(i + 1, n))) % mod + mod) % mod;
            
            pre0.add(i, -ksm(2, i - 1));
            suf0.add(i, -ksm(2, n - i));
            pre1.add(i, ksm(2, i - 1));
            suf1.add(i, ksm(2, n - i));
            s[i] = '1';
        }
        else
        {
            ans = (ans + (pre1.query(1, i - 1)) + (suf1.query(i + 1, n)) + 2 * (pre1.query(1, i - 1)) * (suf1.query(i + 1, n))) % mod;
            ans = ((ans - (pre0.query(1, i - 1)) - (suf0.query(i + 1, n)) - 2 * (pre0.query(1, i - 1)) * (suf0.query(i + 1, n))) % mod + mod) % mod;
            
            pre1.add(i, -ksm(2, i - 1));
            suf1.add(i, -ksm(2, n - i));
            pre0.add(i, ksm(2, i - 1));
            suf0.add(i, ksm(2, n - i));
            s[i] = '0';
        }
        cout << ans << ' ';
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