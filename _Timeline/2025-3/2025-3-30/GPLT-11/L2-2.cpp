#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[10004];
int leaf[10004];
vector<int> ans, res;

void dfs(int x)
{
    if (leaf[x])
    {
        res.push_back(x);
        if (ans.size() < res.size() || ans.size() == res.size() && res < ans)
        {
            ans = res;
        }
        res.pop_back();
        return;
    }

    res.push_back(x);
    for (auto &v : g[x])
    {
        dfs(v);
    }
    res.pop_back();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k == 0)
            leaf[i] = 1;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
            vis[x] = 1;
        }
    }

    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0) cout << ' ';
        cout << ans[i];
    }

    return 0;
}