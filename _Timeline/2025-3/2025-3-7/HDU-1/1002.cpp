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
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int inv2 = ksm(2, mod - 2);

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vector<i64> a(k + 1);
    for (int i = 0; i <= k; i++)
        cin >> a[i];
    
    i64 me = a[0];

    vector<i64> vec(__lg(n) + 9); 
    for (int i = 1; i <= k; i++)
    {
        // 你到什么时候能对 染染 影响
        i64 cur = 0;
        while ((me - 1) / (1LL << cur) != (a[i] - 1) / (1LL << cur)) cur++;

        // 你有多大的概率能活到那个时候
        i64 p = 1;
        for (i64 j = 2; __lg(j) < cur; j *= 2)
        {
            i64 up = min(n, (a[i] + j - 1) / j * j);
            i64 low = (a[i] - 1) / j * j;
            if (up - low != 1)
                p = (p * inv2) % mod;
        }
        vec[cur] = (vec[cur] + p) % mod;
    }
    i64 ans = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        ans = ans * (1 - vec[i] + mod) % mod;
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