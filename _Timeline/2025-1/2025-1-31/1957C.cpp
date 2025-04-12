#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;

i64 A[maxn];

void init()
{
    A[0] = A[1] = 1;
    for (int i = 2; i <= 3e5; i++)
    {
        A[i] = (A[i - 1] * i) % mod;
    }
}

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

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vis(n + 1);
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        vis[u] = 1;
        vis[v] = 1;
    }

    i64 ans = 0, res = 1;
    int cnt = 0;
    i64 cur = count(vis.begin() + 1, vis.end(), 0);
    while (cur >= 2)
    {
        ans = (ans + res * ksm(A[cnt], mod - 2)) % mod;
        res = (res * 2 * (((cur - 1) * cur / 2) % mod)) % mod;
        cur -= 2;
        cnt++;
    }
    ans = (ans + res * ksm(A[cnt], mod - 2)) % mod;
    cout << ans << '\n';
}

int main()
{
    init();

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}