#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    priority_queue<int> q;
    i64 ans = 0;
    for (int i = 1; i <= n; i++)
    {
        q.push(a[i]);
        if ((n - i + 1) % (k + 1) == 0)
        {
            ans += q.top();
            q.pop();
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