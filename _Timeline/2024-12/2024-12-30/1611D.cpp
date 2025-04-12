#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    just keep the p[i]'s weigh is i.

    notice the implemention. 
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> ans(n + 1);

    int ok = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
        b[x] = i;
        if (b[a[x]] == 0)
        {
            ok = 0;
        }
        else
        {
            ans[x] = i - b[a[x]];
        }
        
    }

    if (!ok)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];

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