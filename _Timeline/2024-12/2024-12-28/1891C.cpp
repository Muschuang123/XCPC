#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    multiset<int> ss;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ss.insert(x);
    }

    int ans = 0;
    int cnt = 0;
    while (ss.size() > 1)
    {
        int l = *ss.begin();
        int r = *--ss.end();
        if (cnt + l >= r)
        {
            l -= r - cnt;
            ans += r - cnt + 1;
            cnt = 0;
            ss.erase(ss.begin());
            ss.erase(--ss.end());
            if (l > 0)
                ss.insert(l);
        }
        else
        {
            ans += l;
            cnt += l;
            ss.erase(ss.begin());
        }

        cout << "\0";
    }

    if (ss.size())
    {
        if (*ss.begin() == 1)
        {
            ans++;
        }
        else
        {
            ans += (*ss.begin() - cnt + 1) / 2 + 1;
        }
        
    }

    cout << ans << '\n';

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