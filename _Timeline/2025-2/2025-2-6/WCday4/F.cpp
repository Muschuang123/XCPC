#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    i64 n, p, k;
    cin >> n >> p >> k;

    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= p;
    }
    sort(a.begin() + 1, a.end());

    vector<int> lim(n + 1);
    for (int i = 1; i <= n; i++)
    {
        lim[i] = lower_bound(a.begin() + 1, a.end(), p - a[i]) - a.begin();
    }

    auto check = [&](i64 mid) -> bool
    {
        i64 cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (lim[i] > i)
                cnt += a.begin() + lim[i] - lower_bound(a.begin() + max(1, i + 1), a.begin() + lim[i], mid - a[i]);
            cnt += a.end() - lower_bound(a.begin() + max(lim[i], i + 1), a.end(), mid + p - a[i]);
        }
        return cnt >= k;
    };

    i64 l = -1, r = p;
    while (l + 1 < r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        for (int j = lim[i] - 1; j > i && a[i] + a[j] > l; j--)
        {
            vec.push_back(a[i] + a[j]);
        }
        for (int j = n; j >= lim[i] && j > i && a[i] + a[j] > l + p; j--)
        {
            vec.push_back(a[i] + a[j] - p);
        }
    }

    sort(vec.begin(), vec.end());

    while (vec.size() && k--)
    {
        cout << vec.back() << ' ';
        vec.pop_back();
    }
    for (int i = 1; i <= k; i++)
    {
        cout << l << ' ';
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