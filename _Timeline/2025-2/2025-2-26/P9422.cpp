#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    int pa = 1, pb = 1;
    int ans = 0;
    i64 sa = 0, sb = 0;
    while (pa <= n || pb <= m)
    {
        if (sa == sb && sa != 0)
        {
            ans++;
            sa = sb = 0;
        }
        if (sa > sb && pb <= m)
        {
            sb += b[pb++];
        }
        else
        {
            sa += a[pa++];
        }
    }
    if (sa == sb && sa != 0)
    {
        ans++;
        sa = sb = 0;
    }

    cout << n + m - 2 * ans;

    return 0;
}
