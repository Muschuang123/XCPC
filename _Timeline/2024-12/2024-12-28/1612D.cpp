#include <bits/stdc++.h>
#define int long long
using namespace std;

int x;

bool dfs(int a, int b)
{
    if (a > b)
        swap(a, b);
    
    if (b < x || a == 0)
        return 0;
    if (a == x || b == x || b % a == x % a)
        return 1;
    
    return dfs(a, b % a);
}

void solve()
{
    int a, b;
    cin >> a >> b >> x;

    if (dfs(a, b))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}