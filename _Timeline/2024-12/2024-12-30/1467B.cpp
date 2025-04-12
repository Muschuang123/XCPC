#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    the best choice for every i from 1 to n is let a[i] = a[i - 1] or a[i] = a[i + 1]

    just brute force do it, and check the answer.
*/

int n;
vector<int> a;

bool isHill(int i)
{
    return i > 1 && i < n && a[i] > a[i - 1] && a[i] > a[i + 1];
}

bool isValley(int i)
{
    return i > 1 && i < n && a[i] < a[i - 1] && a[i] < a[i + 1];
}

int surroundValue(int i)
{
    return isValley(i - 1) + isValley(i) + isValley(i + 1) + 
        isHill(i - 1) + isHill(i) + isHill(i + 1);
}

void solve()
{
    cin >> n;
    a.clear();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    if (n <= 2)
    {
        cout << 0 << '\n';
        return;
    }

    // 1 == hill   2 == valley
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (isValley(i) || isHill(i))
            ans++;
    }
    int res = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        int d = surroundValue(i);
        int t = a[i];

        a[i] = a[i - 1];
        res = max(res, d - surroundValue(i));
        
        a[i] = a[i + 1];
        res = max(res, d - surroundValue(i));

        a[i] = t;
    }
    cout << ans - res << '\n';
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