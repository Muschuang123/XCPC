#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 看了好几个方法都不如我这个。
// O(nlog2e5) + O(q)，光速跑完

bool vis[400005];
#define vis(x) vis[x + (int)2e5]

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vector<i64> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    i64 sa = accumulate(a.begin() + 1, a.end(), 0LL);
    i64 sb = accumulate(b.begin() + 1, b.end(), 0LL);
    
    for (int i = 1; i <= n; i++) a[i] = sa - a[i];
    for (int i = 1; i <= m; i++) b[i] = sb - b[i];
    
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    n = unique(a.begin() + 1, a.end()) - a.begin() - 1;
    m = unique(b.begin() + 1, b.end()) - b.begin() - 1;

    int idx = lower_bound(b.begin() + 1, b.end(), 0LL) - b.begin();

    for (int i = 1; i <= n; i++)
    {
        for (int j = idx - 1; j >= 1 && abs(a[i] * b[j]) <= 2e5; j--)
        {
            vis(a[i] * b[j]) = 1;
        }
        for (int j = idx; j <= m && abs(a[i] * b[j]) <= 2e5; j++)
        {
            vis(a[i] * b[j]) = 1;
        }
    }

    while (q--)
    {
        int x;
        cin >> x;
        cout << (vis(x) ? "YES" : "NO") << '\n';
    }

    return 0;
}