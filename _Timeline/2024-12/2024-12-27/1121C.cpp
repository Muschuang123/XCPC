#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    // now test
    vector<int> a(k + 1);
    // goal
    vector<int> b(k + 1, -1);
    vector<bool> vis(k + 1);

    int cnt = 0;
    while (cnt < n)
    {
        int d = round(100.0 * (double)cnt / (double)n);
        for (int i = 1; i <= k; i++)
        {
            if (a[i] == -1)
                continue;
            a[i]++;
            if (a[i] == d && !vis[i])
            {
                ans++;
                vis[i] = 1;
            }
            if (a[i] == b[i] || b[i] == -1)
            {
                if (b[i] != -1)
                    cnt++;
                if (q.size())
                {
                    b[i] = q.front();
                    q.pop();
                    a[i] = 0;
                    vis[i] = 0;
                }
                else
                {
                    a[i] = -1;
                    continue;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}