#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        int op, ind;
        cin >> op >> ind;
        if (op == 1)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[ind][j];
            }
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[j][ind];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " \n"[j == n];
        }
    }

    return 0;
}