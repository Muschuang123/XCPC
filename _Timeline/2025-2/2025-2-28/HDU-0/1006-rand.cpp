#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


void solve()
{
    srand(57);
    int tt = rand() % 30;
    cout << tt << '\n';
    while (tt--)
    {
        int n = rand() % 100;
        for (int i = 1; i <= n; i++)
        {
            int d = rand() % 5;
            if (d == 0) cout << "Y";
            if (d == 1) cout << "E";
            if (d == 2) cout << "S";
            if (d == 3) cout << "N";
            if (d == 4) cout << "O";
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        solve();
    return 0;
}