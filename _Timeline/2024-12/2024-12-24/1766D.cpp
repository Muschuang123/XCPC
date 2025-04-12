#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e7 + 8;

vector<int> pri;
bool not_prime[maxn];
// 查找素因子时，找出每个数最小的素因子。
int minp[maxn];
void primer(int n)
{
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
            minp[i] = i;
        }
        for (int j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            minp[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
}

void solve()
{
    int x, y;
    cin >> x >> y;
    int z = y - x;
    if (z == 1)
    {
        cout << -1 << '\n';
        return;
    }

    if (__gcd(x, y) != 1)
    {
        cout << 0 << '\n';
        return;
    }

    int ans = 1e9 + 7;
    while (z != 1)
    {
        int p = minp[z];
        ans = min(ans, p - x % p);
        while (z % p == 0) 
            z /= p; 
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    primer(1e7 + 7);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}