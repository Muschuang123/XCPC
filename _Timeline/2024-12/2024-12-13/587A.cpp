#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[2000006] = {0};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    // vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    
    for (int i = 0; i <= 2e6; i++)
    {
        if (a[i] >= 2)
        {
            a[i + 1] += a[i] / 2;
            a[i] &= 1;
        }
    }

    int res = 0;
    int ans = 0;
    for (int i = 0; i <= 2e6; i++)
    {
        res = min(a[i], res);
        a[i] -= res;
        res += a[i] / 2;
        ans += a[i] / 2;
        ans += a[i] & 1;
    }
    cout << ans;

    return 0;
}