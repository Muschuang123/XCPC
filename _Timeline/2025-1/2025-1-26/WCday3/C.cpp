#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i].size();
        mx = max(mx, (int)a[i].size());
    }
    ans *= 2;
    ans -= mx;
    int l,r ;
    cin >> l >> r;

    sort(a.begin() + 1, a.end());
    int la = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < min(a[i - 1].size(), a[i].size()); j++)
        {
            if (a[i - 1][j] != a[i][j])
                break;
            cnt++;
        }
        ans -= cnt * 2;
        // ans -= max(0LL, cnt - la) * 2;
        la = cnt;
        cout << "";
    }
    cout << ans << '\n';

    return 0;
}