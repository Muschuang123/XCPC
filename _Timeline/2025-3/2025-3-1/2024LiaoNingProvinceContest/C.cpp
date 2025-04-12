#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;

vector<int> g[maxn];
vector<i64> need, have, a;
bool leaf[maxn];

i64 dfs(int x, int fa)
{
    i64 res = 0;
    for (int v : g[x])
    {
        if (v == fa)
            continue;
        if (leaf[v])
        {
            res += a[v];
            continue;
        }
        res += dfs(v, x);
    }
    have.push_back(a[x]);
    need.push_back(res);
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 1)
            leaf[i] = 1;
    }

    i64 mx = 0;
    for (int v : g[0])
    {
        if (leaf[v])
        {
            mx += a[v];
            continue;
        }
        mx += dfs(v, 0);
    }
    if (mx > 2200)
    {
        cout << "NO\n";
        return 0;
    }

    sort(have.begin(), have.end(), greater<>());
    sort(need.begin(), need.end(), greater<>());
    for (int i = 0; i < have.size(); i++)
    {
        if (need[i] > have[i])
        {
            cout << "NO\n";
            return 0;
        }
    }    
    cout << "YES\n";

    return 0;
}