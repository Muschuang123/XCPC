#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// pre : 4 1 3 2 6 5 7
// mid : 1 2 3 4 5 6 7

vector<int> g[300001];

void dfs(vector<int> &pre, vector<int> &mid, int fa)
{
    if (pre.empty())
        return;
    int p = pre.front();
    g[fa].push_back(p);
    int k = -1;
    vector<int> lpre, lmid, rpre, rmid;
    for (int i = 0; i < mid.size(); i++)
    {
        if (mid[i] == p)
        {
            k = i;
            break;
        }
        else
        {
            lmid.push_back(mid[i]);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        lpre.push_back(pre[i]);
    }
    for (int i = k + 1; i < pre.size(); i++)
    {
        rpre.push_back(pre[i]);
        rmid.push_back(mid[i]);
    }

    dfs(lpre, lmid, p);
    dfs(rpre, rmid, p);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> pre, mid;
    int n;
    cin >> n;
    pre.resize(n);
    mid.resize(n);
    for (int i = 0; i < n; i++) cin >> mid[i];
    for (int i = 0; i < n; i++) cin >> pre[i];
    dfs(pre, mid, 0);
    int ro = pre.front();

    for (int i = 1; i <= 3e5; i++)
    {
        if (g[i].size() == 2)
            swap(g[i].front(), g[i].back());
    }

    // bfs
    queue<int> q;
    q.push(ro);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (x != ro)
            cout << ' ';
        cout << x;
        for (auto &v : g[x])
            q.push(v);
    }

    return 0;
}