#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

void solve()
{
    i64 k, x, y;
    cin >> k >> y >> x;
    i64 ans = 0;
    if (k == 1)
    {
        cout << x + y << '\n';
        return;
    }
    else if (k % 2)
    {
        i64 need = k / 2;
        i64 cons = min(x / need, y);
        ans += cons;
        x -= need * cons;
        y -= cons;
        i64 t = k;
        if (y != 0)
        {
            t -= x * 2;
            if (y >= t)
            {
                y -= t;
                ans++;
                ans += y / k;
            }
        }
        else
        {
            need++;
            ans += x / need;
        }
    }
    else
    {
        i64 need = k / 2;
        ans += x / need;
        x %= need;
        i64 t = k;
        t -= x * 2;
        if (y >= t)
        {
            ans++;
            y -= t;
            ans += y / k;
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
}