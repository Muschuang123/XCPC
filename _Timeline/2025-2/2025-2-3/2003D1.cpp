#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    i64 m;
    cin >> n >> m;
    vector<int> a;
    i64 res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        a.clear();
        a.resize(l + 1);
        for (int j = 1; j <= l; j++)
        {
            cin >> a[j];
        }
        sort(a.begin() + 1, a.end());
        int can = 1;
        i64 cur = 0;
        for (int j = 1; j <= l; j++)
        {
            if (a[j] == cur)
            {
                cur++;
            }
            else if (a[j] > cur && can)
            {
                cur++;
                can = 0;
                if (a[j] == cur)
                {
                    cur++;
                }
            }
        }
        cur += can;
        res = max(res, cur);
    }

    i64 ans = 0; 
    if (m >= res)
        ans = m * (m + 1) / 2 + res * (res + 1) / 2;
    else 
        ans = (m + 1) * res;
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