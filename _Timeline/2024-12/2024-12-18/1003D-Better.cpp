#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(70);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[__builtin_ctz(x)]++;
    }

    while (q--)
    {
        int x;
        cin >> x;
        int ans = 0;
        // 倒着拿保证个数最少
        for (int i = 32; i >= 0; i--)
        {
            // 对于每一位，能拿多少拿多少。
            // 因为都是 power of 2，所以不会出现拿多了的情况。
            int get = min(x / (1 << i), a[i]);
            ans += get;
            x -= get << i;
        }
        cout << (x ? -1 : ans) << '\n';
    }
    


    return 0;
}