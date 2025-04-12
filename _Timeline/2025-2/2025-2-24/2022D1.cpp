#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n / 2; i++)
    {
        int a = 2 * i - 1, b = 2 * i;
        cout << "? " << a << ' ' << b << endl;
        int x;
        cin >> x;
        cout << "? " << b << ' ' << a << endl;
        int y;
        cin >> y;
        if (x != y)
        {
            int j = 1;
            while (j == a || j == b) j++;
            cout << "? " << a << ' ' << j << endl;
            int xx;
            cin >> xx;
            cout << "? " << j << ' ' << a << endl;
            int yy;
            cin >> yy;
            if (xx == yy)
            {
                cout << "! " << b << endl;
            }
            else
            {
                cout << "! " << a << endl;
            }
            return;
        }
    }
    cout << "! " << n << endl;
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