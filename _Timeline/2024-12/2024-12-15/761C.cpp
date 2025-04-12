#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 0x3f3f3f3f;

int n, m;
vector<string> a;
vector<vector<int>> b;
int ans = inf;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1);
    b.resize(n + 1, vector<int>(4, inf));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] >= '0' && a[i][j] <= '9')
                b[i][1] = min({b[i][1], j, m - j});
            if (a[i][j] >= 'a' && a[i][j] <= 'z')
                b[i][2] = min({b[i][2], j, m - j});
            if (a[i][j] == '#' || a[i][j] == '*' || a[i][j] == '&')
                b[i][3] = min({b[i][3], j, m - j});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (b[i][1] == inf)
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j || b[j][2] == inf)
                continue;
            for (int k = 1; k <= n; k++)
            {
                if (i == k || j == k || b[k][3] == inf)
                    continue;
                int res = 0;
                for (int c = 1; c <= n; c++)
                {
                    if (c == i)
                    {
                        res += b[c][1];
                    }
                    else if (c == j)
                    {
                        res += b[c][2];
                    }
                    else if (c == k)
                    {
                        res += b[c][3];
                    }
                    else
                    {
                        res += min({b[c][1], b[c][2], b[c][3]});
                    }
                }
                ans = min(ans, res);
            }
        }
    }

    cout << ans;

    return 0;
}