#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct qu
{
    int r, a, i, ans;
};

bool cmp1(const qu &a, const qu &b)
{
    return a.r < b.r || a.r == b.r && a.a < b.a;
}

bool cmp2(const qu &a, const qu &b)
{
    return a.i < b.i;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<qu> q(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].r >> q[i].a;
        q[i].i = i;
    }

    sort(q.begin() + 1, q.end(), cmp1);
    int p = 1;

    vector<int> dp;
    for (int i = 1; i <= n; i++)
    {
        if (dp.empty() || a[i] > dp.back())
        {
            dp.push_back(a[i]);
        }
        else
        {
            *lower_bound(dp.begin(), dp.end(), a[i]) = a[i];
        }

        while (p <= m && q[p].r == i)
        {
            q[p].ans = upper_bound(dp.begin(), dp.end(), q[p].a) - dp.begin();
            p++;
        }
    }

    sort(q.begin() + 1, q.end(), cmp2);

    for (int i = 1; i <= m; i++)
    {
        cout << q[i].ans << '\n';
    }

    return 0;
}