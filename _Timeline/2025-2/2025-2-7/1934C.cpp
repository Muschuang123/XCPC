#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << "? 1 1" << endl;
    int len1;
    cin >> len1;
    cout << "? " << n << ' ' << m << endl;
    int len2;
    cin >> len2;
    cout << "? " << n << ' ' << 1 << endl;
    int len3;
    cin >> len3;
    if (len1 + len3 >= n - 1 && (len1 + len3 - (n - 1)) % 2 == 0)
    {
        int fee = (len1 + len3 - (n - 1)) / 2;
        int x = len1 - fee + 1;
        int y = fee + 1;
        cout << "? " << x << ' ' << y << endl;
        int len4;
        cin >> len4;
        if (len4 == 0)
        {
            cout << "! " << x << ' ' << y << endl;
        }
        else
        {
            fee = (len2 + len3 - (m - 1)) / 2;
            x = n - fee;
            y = len3 - fee + 1;
            cout << "! " << x << ' ' << y << endl;
        }
    }
    else
    {
        int fee, x, y;
        fee = (len2 + len3 - (m - 1)) / 2;
        x = n - fee;
        y = len3 - fee + 1;
        cout << "! " << x << ' ' << y << endl;
    }
    
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}