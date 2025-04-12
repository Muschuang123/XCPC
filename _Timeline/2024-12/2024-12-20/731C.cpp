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

    int n, m, k;
    cin >> n >> m >> k;
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        merg(x, y);
    }

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[fin(i)].push_back(a[i]);
    }

    int ans = 0;
    for (auto &i : mp)
    {
        map<int, int> co;
        for (auto &j : i.second)
        {
            co[j]++;
        }
        int mx = 0;
        for (auto &j : co)
        {
            mx = max(mx, j.second);
        }
        ans += i.second.size() - mx;
    }

    cout << ans;

    return 0;
}