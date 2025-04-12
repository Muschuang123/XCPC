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
        for (int j = 1; j <= n; j++)
        {
            char t = s[j];
            s[j] = 'N';
            vector<vector<i64>> aa(n + 1, vector<i64>(5));
            for (int i = 1; i <= n; i++)
            {
                aa[i] = aa[i - 1];
                if (s[i] == 'Y')
                    aa[i][0]++;
                if (s[i] == 'E')
                    aa[i][1] += aa[i][0];
                if (s[i] == 'S')
                    aa[i][2] += aa[i][1];
                if (s[i] == 'N')
                    aa[i][3]++;
                if (s[i] == 'O')
                    aa[i][4] += aa[i][3];
            }
            if (aa[n][4] > aa[n][2])
            {
                cout << "O BUDUI BUDUI\n";
                return;
            }
            s[j] = t;
        }
        for (int j = 1; j <= n; j++)
        {
            char t = s[j];
            s[j] = 'O';
            vector<vector<i64>> aa(n + 1, vector<i64>(5));
            for (int i = 1; i <= n; i++)
            {
                aa[i] = aa[i - 1];
                if (s[i] == 'Y')
                    aa[i][0]++;
                if (s[i] == 'E')
                    aa[i][1] += aa[i][0];
                if (s[i] == 'S')
                    aa[i][2] += aa[i][1];
                if (s[i] == 'N')
                    aa[i][3]++;
                if (s[i] == 'O')
                    aa[i][4] += aa[i][3];
            }
            if (aa[n][4] > aa[n][2])
            {
                cout << "O BUDUI BUDUI\n";
                return;
            }
            s[j] = t;
        }
        cout << "DUI DE\n";
    }
    else
    {
        for (int j = 1; j <= n; j++)
        {
            char t = s[j];
            s[j] = 'Y';
            vector<vector<i64>> aa(n + 1, vector<i64>(5));
            for (int i = 1; i <= n; i++)
            {
                aa[i] = aa[i - 1];
                if (s[i] == 'Y')
                    aa[i][0]++;
                if (s[i] == 'E')
                    aa[i][1] += aa[i][0];
                if (s[i] == 'S')
                    aa[i][2] += aa[i][1];
                if (s[i] == 'N')
                    aa[i][3]++;
                if (s[i] == 'O')
                    aa[i][4] += aa[i][3];
            }
            if (aa[n][4] < aa[n][2])
            {
                cout << "O DUI DE\n";
                return;
            }
            s[j] = t;
        }
        for (int j = 1; j <= n; j++)
        {
            char t = s[j];
            s[j] = 'E';
            vector<vector<i64>> aa(n + 1, vector<i64>(5));
            for (int i = 1; i <= n; i++)
            {
                aa[i] = aa[i - 1];
                if (s[i] == 'Y')
                    aa[i][0]++;
                if (s[i] == 'E')
                    aa[i][1] += aa[i][0];
                if (s[i] == 'S')
                    aa[i][2] += aa[i][1];
                if (s[i] == 'N')
                    aa[i][3]++;
                if (s[i] == 'O')
                    aa[i][4] += aa[i][3];
            }
            if (aa[n][4] < aa[n][2])
            {
                cout << "O DUI DE\n";
                return;
            }
            s[j] = t;
        }
        for (int j = 1; j <= n; j++)
        {
            char t = s[j];
            s[j] = 'S';
            vector<vector<i64>> aa(n + 1, vector<i64>(5));
            for (int i = 1; i <= n; i++)
            {
                aa[i] = aa[i - 1];
                if (s[i] == 'Y')
                    aa[i][0]++;
                if (s[i] == 'E')
                    aa[i][1] += aa[i][0];
                if (s[i] == 'S')
                    aa[i][2] += aa[i][1];
                if (s[i] == 'N')
                    aa[i][3]++;
                if (s[i] == 'O')
                    aa[i][4] += aa[i][3];
            }
            if (aa[n][4] < aa[n][2])
            {
                cout << "O DUI DE\n";
                return;
            }
            s[j] = t;
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