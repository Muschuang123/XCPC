#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(1e6 + 1);
    vector<int> in(n + 1);
    vector<vector<int>> b(n + 1);
    vector<int> c(1e6 + 1);
    vector<int> vis(1e6 + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        in[i] = x;
        c[x] = i;
        if (!vis[x] && x != 0)
        {
            q.push(x);
            vis[x] = 1;
            a[x]++;
        }
        if (a[x] == 2)
        {
            a[x]++;
            b[i].push_back(x);
        }
        if (x == 0)
        {
            while(q.size())
            {
                int t = q.front();
                q.pop();
                a[t]++;
            }
        }
    }

    i64 ans = 0;
    set<int> ss;
    for (int i = 1; i <= n; i++)
    {
        int fl = 0;
        while (b[i].size())
        {
            int x = b[i].back();
            b[i].pop_back();
            ss.insert(x);
            if (x == in[i])
                fl = 1;
        }
        if (in[i] != 0 && c[in[i]] == i)
        {
            ans += (int)ss.size() - fl;
        }
    }
    cout << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}