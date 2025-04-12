#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++)
    {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+')
        {
            a[i] = x;
        }
        else
        {
            a[i] = -x;
        }
        cin >> op >> x;
        if (op == '+')
        {
            b[i] = x;
        }
        else
        {
            b[i] = -x;
        }
    }
    vector<int> na(n + 2, n + 1), nb(n + 2, n + 1);
    for (int i = n; i >= 1; i--)
    {
        na[i] = na[i + 1];
        nb[i] = nb[i + 1];
        if (a[i + 1] < 0 && a[i + 1] == b[i + 1])
            continue;
        if (a[i + 1] < 0)
            na[i] = i + 1;
        if (b[i + 1] < 0)
            nb[i] = i + 1;
    }

    i64 ca = 1, cb = 1;
    for (int i = 1; i <= n; i++)
    {
        i64 ta = ca, tb = cb;
        if (a[i] >= 0)
            ca += a[i];
        else 
            ca *= -a[i];
        
        if (b[i] >= 0)
            cb += b[i];
        else 
            cb *= -b[i];
        
        if (na[i] < nb[i] || na[i] == nb[i] && na[i] <= n && a[na[i]] < b[nb[i]])
        {
            ca += cb - tb;
            cb = tb;
        }
        else if (nb[i] < na[i] || na[i] == nb[i] && na[i] <= n && a[na[i]] > b[nb[i]])
        {
            cb += ca - ta;
            ca = ta;
        }
        cout << "";
    }
    cout << ca + cb << '\n';
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