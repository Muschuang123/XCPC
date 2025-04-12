#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    vector<pair<i64, i64>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;

    sort(a.begin() + 1, a.end());

    if (a.back().second == 1)
    {
        // 如果最大的可加，直接加完
        cout << a.back().first + k + a[n / 2].first << '\n';
    }
    else
    {
        i64 ans = k;
        int ti = 0;
        for (int i = n; i >= 1; i--)
        {
            if (a[i].second == 1)
            {
                ans += a[i].first;
                ti = i;
                break;
            } 
        }
        if (ans == k)
        {
            // 一个 1 也没有，取最大的 + 其余的中位数
            cout << a.back().first + a[n / 2].first << '\n';
        }
        else
        {
            auto check = [&](int mid)
            {
                i64 t = k;
                vector<pair<i64, i64>> b = a;
                int cnt = 0;
                for (int i = n - 1; i >= 1; i--)
                {
                    if (mid > b[i].first && b[i].second == 1)
                    {
                        t -= mid - b[i].first;
                        b[i].first = mid;
                    }
                    if (t < 0)
                        break;
                    if (b[i].first >= mid)
                        cnt++;
                }
                return cnt >= (n + 1) / 2;
            };

            int l = 1, r = 1e9 + 1;
            while (l + 1 < r)
            {
                int mid = l + r >> 1;
                if (check(mid))
                    l = mid;
                else 
                    r = mid;
            }

            vector<i64> vec(1);
            for (int i = 1; i <= n; i++)
            {
                if (i != ti)
                    vec.push_back(a[i].first);
            }

            // 1. 取 0 最大的 + 二分，从大往小，
            //      看看能不能在 k 次操作内 出现 (n + 1) / 2 个 mid
            // 2. 取 1 最大的，用 k 加满，然后取剩下的中位数
            cout << max(ans + vec[n / 2], 1LL * l + a.back().first) << '\n';
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