#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    
    int cnt = 0;
    vector<array<int, 3>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]] == 1)
            cnt++;
        else 
            cnt = 0;
        if (cnt)
            ans.push_back({cnt, i - cnt + 1, i});
    }
    sort(ans.begin(), ans.end(), greater<>());
    if (ans.empty())
    {
        cout << 0 << '\n';
    }
    else
    {
        cout << ans[0][1] << ' ' << ans[0][2] << '\n';
    }
    
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