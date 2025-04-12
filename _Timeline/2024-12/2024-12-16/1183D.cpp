#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<pair<int, int>> sw;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 0)
        {
            sw.push_back({a[i], i});
        }
    }
    sort(sw.begin(), sw.end(), greater<>());
    int ans = 0;
    int last = sw.front().first + 1;
    for (auto &c : sw)
    {
        if (c.first >= last)
        {
            c.first = last - 1;
        }
        if (c.first == 0)
            break;
        ans += c.first;
        last = c.first;
    }
    
    cout << ans << '\n';

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