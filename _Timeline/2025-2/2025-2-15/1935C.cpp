#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    
    sort(a.begin() + 1, a.end());
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        priority_queue<int> q;
        i64 sum = -(a[l].first - a[l - 1].first);
        for (int r = l; r <= n; r++)
        {
            q.push(a[r].second);
            sum += a[r].first - a[r - 1].first;
            sum += a[r].second;
            while (q.size() && sum > k)
            {
                sum -= q.top();
                q.pop();
            }
            ans = max(ans, (int)q.size());
        }
    }
    cout << ans << '\n';
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