#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n, m;
string s;
vector<string> a;
vector<int> vis;
vector<int> cur;

void dfs(int x)
{
    if (x + 1 == s.size())
    {
        for (int i = 0; i < cur.size(); i++)
        {
            if (i > 0)
                cout << ' ';
            cout << cur[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i] && s.substr(x, a[i].size()) == a[i])
        {
            vis[i] = 1;
            cur.push_back(i);
            dfs(x + a[i].size() - 1);
            cur.pop_back();
            vis[i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c;
        cin >> c;
        s.push_back(c);
    }
    cin >> m;
    a.resize(n + 1);
    vis.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int c;
            cin >> c;
            a[i].push_back(c);
        }
    }

    dfs(0);

    return 0;
}