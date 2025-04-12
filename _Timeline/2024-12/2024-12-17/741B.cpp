#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fa;

int fin(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = fin(fa[x]);
}

void merg(int x, int y)
{
    fa[fin(x)] = fin(y);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, W;
    cin >> n >> m >> W;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    vector<int> w(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        merg(x, y);
    }

    map<int, vector<int>> mp;
    vector<int> sw(n + 1);
    vector<int> sb(n + 1);
    for (int i = 1; i <= n; i++)
    {
        mp[fin(i)].push_back(i);
        sw[fin(i)] += w[i];
        sb[fin(i)] += b[i];
    }

    vector<int> dp(W + 1);
    for (auto &c : mp)
    {
        int i = c.first;
        for (int j = W; j >= 1; j--)
        {
            if (j - sw[i] >= 0)
                dp[j] = max(dp[j], dp[j - sw[i]] + sb[i]);
            for (auto &k : mp[i])
                if (j - w[k] >= 0)
                    dp[j] = max(dp[j], dp[j - w[k]] + b[k]);
        }
    }

    cout << *max_element(dp.begin() + 1, dp.end());

    return 0;
}