#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 对于奇数其中的特殊情况，一定是删掉 序号为奇数的元素 更优。
 * 因为如果删掉偶数的话，还不如删掉 第一个元素。（会额外增加一段）
 * 因此，我们可以先把删掉第一个元素的情况求出来，
 * 然后遍历每个 序号为奇数的元素，试图删掉他，更新答案。
 */

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i] % k].push_back(a[i]);
    }

    int cnt = 0;
    for (auto &v : mp)
    {
        if (v.second.size() % 2)
            cnt++;
    }
    if (cnt > n % 2)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    for (auto [tmp, v] : mp)
    {
        if (v.size() % 2 == 0 || v.size() == 1)
        {
            for (int i = 1; i < v.size(); i += 2)
            {
                ans += v[i] - v[i - 1];
            }
        }
        else
        {
            int cur = 0;
            // 先求出来删掉第 1 个数之后的情况。
            for (int i = 1; i < v.size(); i += 2)
            {
                cur += v[i + 1] - v[i];
            }

            int res = cur;
            // 然后把删掉每个数的情况都试一试。
            for (int i = 1; i < v.size(); i += 2)
            {
                cur -= v[i + 1] - v[i];
                cur += v[i] - v[i - 1];
                res = min(res, cur);
            }
            ans += res;
        }
    }
    cout << ans / k << '\n';
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