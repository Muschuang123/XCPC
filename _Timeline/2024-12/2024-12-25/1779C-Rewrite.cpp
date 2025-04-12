#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i];
    }

    priority_queue<int> q;
    int sum = 0;
    // 这里不用考虑 a[1] 是因为 
    // a[1] 取多少都对 全体前缀和 的 相对大小 没有影响
    for (int i = m; i >= 2; i--)
    {
        sum += a[i];
        q.push(a[i]);
        if (sum > 0)
        {
            sum -= 2 * q.top();
            q.pop();
            ans++;
        }
    }

    while (q.size())
    {
        q.pop();
    }
    
    sum = 0;
    for (int i = m + 1; i <= n; i++)
    {
        sum += a[i];
        q.push(-a[i]);
        if (sum < 0)
        {
            sum += 2 * q.top();
            q.pop();
            ans++;
        }
    }
    cout << ans << '\n';
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