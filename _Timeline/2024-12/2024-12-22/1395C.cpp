#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    for (int c = 0; c < (1 << 9); c++)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int fl = 0;
            for (int j = 1; j <= m; j++)
            {
                if ((a[i] & b[j] | c) == c)
                {
                    fl = 1;
                    break;
                }
            }
            if (fl)
                cnt++;
            else
                break;
        }
        if (cnt == n)
        {
            cout << c;
            return 0;
        }
    }

    return 0;
}