#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    before reading this. u should read the binary search method.

    on the "bool check()", there are 3 case limit us:
        1. monster's health for each i. 
            (which were considered by initial l setting in "signed main()")
        2. max power need on i's left.
        3. max power need on i's right.
    
    so we just calculate the 2 and 3 in O(n), 
        and update the minimum answer for each i.
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n + 1), bac(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = max(a[i] + n - i, pre[i - 1]);
    }
    
    bac[n] = a[n] + n - 1;
    for (int i = n - 1; i >= 1; i--)
    {
        bac[i] = max(a[i] + i - 1, bac[i + 1]);
    }
    
    int ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        int res = a[i];
        if (i > 1) res = max(res, pre[i - 1]);
        if (i < n) res = max(res, bac[i + 1]);
        ans = min(ans, res);
    }
    cout << ans;

    return 0;
}