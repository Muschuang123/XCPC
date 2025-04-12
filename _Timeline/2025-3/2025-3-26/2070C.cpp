#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto check = [&](int mid)
    {
        int need = 0;
        int fl = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!fl && s[i] == 'B' && a[i] > mid)
            {
                fl = 1;
                need++;
            }
            if (fl && s[i] == 'R' && a[i] > mid)
            {
                fl = 0;
            }
        }
        return need <= k;
    };

    int l = -1, r = *max_element(a.begin() + 1, a.end());
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else 
            l = mid;
    }
    cout << r << '\n';
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