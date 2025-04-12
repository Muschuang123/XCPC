// E题就是，算出a的总和suma，b的总和sumb，减一下得到diff，显然diff是k的倍数。
// 然后对于所有可能的k，都O(n)的check一遍（比方说用桶计个数），就好了。
// 一个剪枝是去掉>1E6的k，因为没有意义，这样能快很多。
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int cnt[1'000'006];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    i64 suma = accumulate(a.begin() + 1, a.end(), 0LL);
    i64 sumb = accumulate(b.begin() + 1, b.end(), 0LL);
    i64 diff = suma - sumb;
    if (diff < 0)
    {
        cout << -1 << '\n';
        return;
    }

    auto check = [&](int k)
    {
        for (int i = 1; i <= n; i++)
        {
            cnt[a[i] % k]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (cnt[b[i]] <= 0)
            {
                // 清空
                for (int i = 1; i <= n; i++)
                    cnt[a[i] % k] = 0;
                return 0;
            }
            cnt[b[i]]--;
        }
        return 1;
    };

    if (check(1e7))
    {
        cout << (int)1e7 << '\n';
        return;
    }

    for (i64 i = 1; i * i <= diff; i++)
    {
        if (diff % i == 0)
        {
            if (i > 1e6)
                continue;
            if (check(i))
            {
                cout << i << '\n';
                return;
            }
            if (diff / i > 1e6)
                continue;
            if (check(diff / i))
            {
                cout << diff / i << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
    return;
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