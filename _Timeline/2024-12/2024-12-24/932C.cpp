#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    if (a < b)
        swap(a, b);

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = i;

    int l;
    for (l = 1; l + a - 1 <= n && (n - l + 1) % b != 0; l += a)
    {
        int r = l + a - 1;
        int t = ans[l];
        for (int i = l; i <= r - 1; i++)
        {
            ans[i] = ans[i + 1];
        }
        ans[r] = t;
    }

    if ((n - l + 1) % b != 0)
    {
        cout << "-1";
        return 0;
    }
    
    for (; l + b - 1 <= n; l += b)
    {
        int r = l + b - 1;
        int t = ans[l];
        for (int i = l; i <= r - 1; i++)
        {
            ans[i] = ans[i + 1];
        }
        ans[r] = t;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';

    return 0;
}