#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    int c1 = 0, c0 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
            c1++;
        else 
            c0++;
    }
    if (c1 == 0 || c0 == 0)
    {
        cout << *max_element(a.begin() + 1, a.end()) << '\n';
        return;
    }
    i64 sum = accumulate(a.begin() + 1, a.end(), 0LL);
    cout << sum - (c1 - 1) << '\n';
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