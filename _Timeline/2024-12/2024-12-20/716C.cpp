#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int scr = 2, lv = 1;
    cout << 2 << '\n';
    for (int i = 2; i <= n; i++)
    {
        cout << i * (i + 1) * (i + 1) - (i - 1) << '\n';
    }

    return 0;
}