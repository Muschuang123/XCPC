#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    // Y E S N O
    vector<vector<i64>> a(n + 1, vector<i64>(5));
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1];
        if (s[i] == 'Y')
            a[i][0]++;
        if (s[i] == 'E')
            a[i][1] += a[i][0];
        if (s[i] == 'S')
            a[i][2] += a[i][1];
        if (s[i] == 'N')
            a[i][3]++;
        if (s[i] == 'O')
            a[i][4] += a[i][3];
    }

    cout << a[n][2] << ' ' << a[n][4] << '\n';
    if (a[n][2] == a[n][4])
    {
        cout << "DUI DUI DUIMA" << '\n';
        return;
    }

    vector<vector<i64>> b(n + 2, vector<i64>(5));
    for (int i = n; i >= 1; i--)
    {
        b[i] = b[i + 1];
        if (s[i] == 'Y')
            b[i][0] += b[i][1];
        if (s[i] == 'E')
            b[i][1] += b[i][2];
        if (s[i] == 'S')
            b[i][2]++;
        if (s[i] == 'N')
            b[i][3] += b[i][4];
        if (s[i] == 'O')
            b[i][4]++;
    }

    vector<i64> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'Y')
            c[i] = b[i][1];
        if (s[i] == 'E')
            c[i] = a[i][0] * b[i][2];
        if (s[i] == 'S')
            c[i] = a[i][1];
        if (s[i] == 'N')
            c[i] = b[i][4];
        if (s[i] == 'O')
            c[i] = b[i][3];
    }

    if (a[n][2] > a[n][4])
    {
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'Y' || s[i] == 'E' || s[i] == 'S')
            if (a[n][2] - c[i] < a[n][4] + max(a[i][3], b[i][4]))
            {
                cout << "O BUDUI BUDUI\n";
                return;
            }
        }
        cout << "DUI DE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == 'N' || s[i] == 'O')
            if (a[n][2] + max({b[i][1], a[i][0] * b[i][2], a[i][1]}) > a[n][4] - c[i])
            {
                cout << "O DUI DE\n";
                return;
            }
        }
        cout << "BUDUI BUDUI\n";
    }

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