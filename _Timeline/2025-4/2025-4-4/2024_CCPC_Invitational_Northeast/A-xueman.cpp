#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll x, m;
    cin >> x >> m;
    ll ans = 0;
    map<ll,int> vis;
    for (int i = 0; i <= m ; i++)
    {
        if (x == 1)
        {
            ans++;
            break;
        }
        if (vis.count(x * x))
        {
            vis[x] = 1;
            ans++;
        }
        else
        {
            vis[x] = 1;
            ans += m - i + 1;
        }
        x = (ll)(sqrtl(x));
    }
    cout << ans << endl;
}