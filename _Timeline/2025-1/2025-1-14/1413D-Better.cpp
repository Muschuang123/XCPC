#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 从后向前。
 * 前面有 + ，就优先拿掉后面的 最小 。
 * 如果充分的这样做了，还是导致 大 出现在 小 的前面的话，就寄。
 * 否则拿的倒序就是答案。
 */

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<char, int>> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i].first;
        if (a[i].first == '-')
            cin >> a[i].second;
    }

    // 找到后面的最小的。
    priority_queue<int, vector<int>, greater<>> q;
    vector<int> ans;
    for (int i = 2 * n; i >= 1; i--)
    {
        if (a[i].first == '-')
        {
            if (q.size() && a[i].second > q.top())
            {
                cout << "NO";
                return 0;
            }
            q.push(a[i].second);
        }
        else
        {
            if (q.empty())
            {
                cout << "NO";
                return 0;
            }
            ans.push_back(q.top());
            q.pop();
        }
    }

    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto &v : ans)
        cout << v << ' ';

    return 0;
}