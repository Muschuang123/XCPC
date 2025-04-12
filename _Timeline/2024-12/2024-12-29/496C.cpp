#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }

    int ans = 0;
    int fl = 1;
    while (fl)
    {
        fl = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i].substr(1, m) > a[i + 1].substr(1, m))
            {
                for (int j = 1; j <= m; j++)
                {
                    if (a[i][j] > a[i + 1][j])
                    {
                        ans++;
                        for (int ii = 1; ii <= n; ii++)
                        {
                            for (int jj = j; jj < m; jj++)
                            {
                                a[ii][jj] = a[ii][jj + 1];
                            }
                        }
                        m--;
                        fl = 1;
                        break;
                    }
                }
                break;
            }
        }
    }
    
    cout << ans;

    return 0;
}