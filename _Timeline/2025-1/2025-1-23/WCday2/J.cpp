#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, h, m;
    cin >> n >> h >> m;
    char t;
    vector<array<int, 6>> a(n + 1);
    vector<string> aa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> aa[i] >> a[i][0] >> t >> a[i][1] >> t >> a[i][2] >> a[i][3] 
            >> t >> a[i][4] >> t >> a[i][5];
    }

    vector<int> ans(4);
    vector<set<string>> ss(4);
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] == h && a[i][1] == m)
        {
            int id = 0;
            if (a[i][3] >= 7 && a[i][3] <= 8 || a[i][3] >= 18 && a[i][3] <= 19 ||
                a[i][3] == 9 && a[i][4] == 0 && a[i][5] == 0 ||
                a[i][3] == 20 && a[i][4] == 0 && a[i][5] == 0)
                id = 1;
            if (a[i][3] >= 11 && a[i][3] <= 12 ||
                a[i][3] == 13 && a[i][4] == 0 && a[i][5] == 0)
                id = 2;
            if (a[i][3] >= 22 || a[i][3] <= 0 ||
                a[i][3] == 1 && a[i][4] == 0 && a[i][5] == 0)
                id = 3;
            if (id == 0 || ss[id].count(aa[i]))
                continue;
            ss[id].insert(aa[i]);
            ans[id]++;
        }
    }

    for (int i = 1; i <= 3; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}