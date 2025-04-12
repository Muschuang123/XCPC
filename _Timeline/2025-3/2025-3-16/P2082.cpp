#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    map<i64, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }

    int acu = 0;
    for (auto &[f, s] : mp)
    {
        mp[f - 1] = acu;
        acu += s;
        s = acu;
    }

    i64 ans = 0;
    i64 la = 0;
    for (auto &[f, s] : mp)
    {
        ans += (bool)s * (f - la);
        la = f;
    }

    cout << ans << '\n';

    return 0;
}