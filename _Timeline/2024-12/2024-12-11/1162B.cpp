#include <bits/stdc++.h>
#define int long long
using namespace std;

bool check(int a, int b, int c, int d)
{
    return a < c && b < d || a < d && b < c;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> b(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    
    bool fl = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i < n)
                fl &= check(a[i][j], b[i][j], a[i + 1][j], b[i + 1][j]);
            if (j < m)
                fl &= check(a[i][j], b[i][j], a[i][j + 1], b[i][j + 1]);
        }

    if (fl)
    {
        cout << "Possible";
    }
    else
    {
        cout << "Impossible";
    }
    

    return 0;
}