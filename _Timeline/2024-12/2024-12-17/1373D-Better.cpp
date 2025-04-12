#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int ans = 0;
    int mnj = 0, mno = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            sum += a[i];
            mnj = min(mnj, sum);
            ans = max(ans, sum - mnj);
        }
        else
        {
            sum -= a[i];
            mno = min(mno, sum);
            ans = max(ans, sum - mno);
        }
    }

    for (int i = 0; i < n; i += 2)
        ans += a[i];

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