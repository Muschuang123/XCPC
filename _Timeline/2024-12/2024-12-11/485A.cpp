#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a, m;
    cin >> a >> m;
    vector<bool> vis(m + 1);
    int p = a;
    while (!vis[p])
    {
        if (p == 0)
        {
            cout << "Yes\n";
            return 0;
        }
        vis[p] = 1;
        p = (p + p % m) % m;
    }
    cout << "No\n";

    return 0;
}