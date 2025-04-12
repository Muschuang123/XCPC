#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 7;
int sum[3][3][maxn];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = " " + s;
    for (int i = 1; i <= n; i += 3)
    {
        for (int j = 0; j < 3 && i + j <= n; j++)
        {
            sum[0][j][i + j] += s[i + j] == 'a';
            sum[1][j][i + j] += s[i + j] == 'b';
            sum[2][j][i + j] += s[i + j] == 'c';
        }
    }
    for (int i = 1; i <= n; i += 3)
    {
        for (int j = 0; j < 3 && i + j <= n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                sum[0][k][i + j] += sum[0][k][i + j - 1];
                sum[1][k][i + j] += sum[1][k][i + j - 1];
                sum[2][k][i + j] += sum[2][k][i + j - 1];
            }
        }
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int res[3][3] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                res[i][j] = sum[i][j][r] - sum[i][j][l - 1];
            }
        }

        int ans = 0;
        ans = max(ans, res[0][0] + res[1][1] + res[2][2]);
        ans = max(ans, res[0][0] + res[1][2] + res[2][1]);
        ans = max(ans, res[0][1] + res[1][0] + res[2][2]);
        ans = max(ans, res[0][1] + res[1][2] + res[2][0]);
        ans = max(ans, res[0][2] + res[1][0] + res[2][1]);
        ans = max(ans, res[0][2] + res[1][1] + res[2][0]);
        cout << r - l + 1 - ans << '\n';
    }
    

    return 0;
}
/*
5
1
baacb
4 5

*/