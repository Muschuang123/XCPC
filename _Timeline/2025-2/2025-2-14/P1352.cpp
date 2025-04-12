// https://www.luogu.com.cn/problem/P1352
// classic: 没有上司的舞会
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[6003];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    for (int i = 1; i < n; i++)
    {
        int l, k;
        cin >> l >> k;
        g[l].push_back(k);
        in[k]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2));
    while (q.size())
    {
        int x = q.front();
        q.pop();
        dp[x][1] += a[x];
        for (int v : g[x])
        {
            if (--in[v] == 0)
                q.push(v);
            dp[v][0] += max(dp[x][0], dp[x][1]);
            dp[v][1] += dp[x][0];
        }
        cout << "";
    }

    int ans = 0;
    for (int i = 1 ; i <= n; i++)
        ans = max({ans, dp[i][0], dp[i][1]});

    cout << ans << '\n';

    return 0;
}