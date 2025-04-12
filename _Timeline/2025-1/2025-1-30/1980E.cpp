#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b)
{
    return *a.begin() < *b.begin();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> ah(n + 1), al(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ah[i].push_back(a[i][j]);
            al[j].push_back(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        sort(ah[i].begin(), ah[i].end());
    for (int j = 1; j <= m; j++)
        sort(al[j].begin(), al[j].end());

    vector<vector<int>> b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> b[i][j];
        }
    }

    vector<vector<int>> bh(n + 1), bl(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            bh[i].push_back(b[i][j]);
            bl[j].push_back(b[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        sort(bh[i].begin(), bh[i].end());
    for (int j = 1; j <= m; j++)
        sort(bl[j].begin(), bl[j].end());

    sort(ah.begin() + 1, ah.end(), cmp);
    sort(al.begin() + 1, al.end(), cmp);
    sort(bh.begin() + 1, bh.end(), cmp);
    sort(bl.begin() + 1, bl.end(), cmp);
    
    if (ah == bh && al == bl)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}