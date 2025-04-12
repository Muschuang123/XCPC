#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    https://blog.csdn.net/qq_37656398/article/details/100863131

    有 k 个人分享 n 种零食，每个人有两种喜欢的零食。
    现在将所有人排成一排，一个人拿着N种零食从前往后走，
    每个人会吃掉他所喜欢的所有零食，若一种也没吃掉就很沮丧。求最少的沮丧的人数。

    考虑将每个人所喜欢的零食连起来，这样问题就变成了一个图论问题。
    对于一个含有 c 个点的连通块，我们可以发现它最多可以满足 c - 1 个人。
        所以 sum{每个联通块中的线数(人数) - (c - 1)} = 沮丧人数。
    
    总人数为 k, 总点数为 n, 总联通块数设为 m. 

    答案为 k - (n - m)。
*/

vector<int> g[100005];
vector<bool> vis;

void dfs(int x)
{
    vis[x] = 1;
    for (auto &v : g[x])
        if (!vis[v])
            dfs(v);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vis.resize(n + 1);

    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        m++;
        dfs(i);
    }
    cout << k - (n - m);

    return 0;
}