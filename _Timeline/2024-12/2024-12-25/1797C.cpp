#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a, b, c;
    cout << "? 1 1" << endl;
    cin >> a;
    cout << "? " << n << ' ' << m << endl;
    cin >> b;
    if (a + b == n - 1)
    {
        cout << "? " << a + 1 << ' ' << 1 << endl;
        cin >> c;
        cout << "! " << a + 1 << ' ' << c + 1 << endl;
        return;
    }
    if (a + b == m - 1)
    {
        cout << "? " << 1 << ' ' << a + 1 << endl;
        cin >> c;
        cout << "! " << c + 1 << ' ' << a + 1 << endl;
        return;
    }
    if (a + 1 <= n && m - b <= m && 0 < a + 1 && 0 < m - b)
    {
        cout << "? " << a + 1 << ' ' << m - b << endl;
        cin >> c;
        if (c == 0)
            cout << "! " << a + 1 << ' ' << m - b << endl;
        else
            cout << "! " << n - b << ' ' << a + 1 << endl;
    }
    else
    {
        cout << "? " << n - b << ' ' << a + 1 << endl;
        cin >> c;
        if (c == 0)
            cout << "! " << n - b << ' ' << a + 1 << endl;
        else
            cout << "! " << a + 1 << ' ' << m - b << endl;
    }
    
    

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}