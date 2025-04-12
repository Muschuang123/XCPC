#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    map<int, int> mx, my;
    int sx = 0, sy = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        mx[a[i].first]++;
        my[a[i].second]++;
        sx += a[i].first;
        sy += a[i].second;
    }

    vector<pair<int, int>> b = a;
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end(), cmp);
    
    if (n % 2 == 0)
        cout << (abs(a[n / 2].first - a[n / 2 + 1].first) + 1) * (abs(b[n / 2].second - b[n / 2 + 1].second) + 1) << '\n';
    else
        cout << 1 << '\n';
    
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