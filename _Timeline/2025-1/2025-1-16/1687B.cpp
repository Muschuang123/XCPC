#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 我的思路：
 * 先用m次查询查出每个路的权重。
 * 带着下标，push进小根堆。
 * 再用m次查询，从小根堆里面取w（路的权重），对于每次查询的路：
 * 如果得到的结果增加了w，说明必须要这条铁路，ans += w。
 * 否则这条铁路可以不要。
 */

int n, m;
vector<int> a;

int ask()
{
    int ans = 0;
    cout << "? ";
    for (int i = 1; i <= m; i++)
    {
        cout << a[i];
    }
    cout << endl;
    cin >> ans;
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a.resize(m + 1);
    vector<int> w(m + 1);
    for (int i = 1; i <= m; i++)
    {
        a[i] = 1;
        w[i] = ask();
        a[i] = 0;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for (int i = 1; i <= m; i++)
    {
        q.push({w[i], i});
    }

    int ans = 0;
    while (q.size())
    {
        auto [w, i] = q.top();
        q.pop();
        a[i] = 1;
        int cur = ask();
        if (cur - ans == w)
        {
            ans = cur;
        }
        else
        {
            a[i] = 0;
        }
    }
    
    cout << "! " << ans << endl;

    return 0;
}