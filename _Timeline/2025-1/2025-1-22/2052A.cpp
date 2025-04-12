#include <bits/stdc++.h>
// #define int long long
using namespace std;

/**
 * 按照最后排名的 倒序 找车。
 * 找到的车和前面的所有车交换一遍，再交换回来。
 * 最后交换到最终位置。
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> cur(n + 1);
    for (int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        cur[i] = i;
    }

    vector<pair<int, int>> ans;
    for (int i = n; i >= 1; i--)
    {
        int l = 1, r = i;
        for (; cur[l] != a[i]; l++);
        // if (l != 1)
        // {
        //     ans.emplace_back(cur[l], cur[l - 1]);
        //     ans.emplace_back(cur[l - 1], cur[l]);
        // }
        for (int j = l; j > 1; j--)
        {
            ans.emplace_back(cur[j], cur[j - 1]);
            swap(cur[j], cur[j - 1]);
        }
        for (int j = 1; j < l; j++)
        {
            ans.emplace_back(cur[j + 1], cur[j]);
            swap(cur[j + 1], cur[j]);
        }

        for (; l < r; l++)
        {
            ans.emplace_back(cur[l + 1], cur[l]);
            swap(cur[l], cur[l + 1]);
        }
    }

    cout << ans.size() << '\n';
    for (auto [f, s] : ans)
    {
        cout << f << ' ' << s << '\n';
    }

    return 0;
}