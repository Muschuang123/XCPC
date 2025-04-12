#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)    
        cin >> a[i];
    
    vector<i64> res(n + 1);
    for (int i = 2; i <= n; i++)
    {
        i64 t = a[i];
        while (t < a[i - 1])
        {
            t <<= 1;
            res[i]++;
        }
        while (t >= a[i - 1] * 2)
        {
            t >>= 1;
            res[i]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        res[i] += res[i - 1];
        // ReLU
        res[i] = max(res[i], 0LL);
    }
    cout << accumulate(res.begin() + 1, res.end(), 0LL) << '\n';
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