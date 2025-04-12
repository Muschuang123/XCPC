#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    double p;
    int n, k;
    cin >> p >> n >> k;
    vector<i64> t0, t1;
    for (int i = 1; i <= n; i++)
    {
        int t, disc;
        cin >> t >> disc;
        if (t == 0)
            t0.push_back(disc);
        else 
            t1.push_back(disc);
    }
    sort(t0.begin(), t0.end());
    sort(t1.begin(), t1.end(), greater<>());
    
    int i = 0, j = 0;
    for (; j < k && j < t0.size(); j++)
        p *= t0[j] / 10.0;
    
    i64 cur = 0;
    for (; i + j < k && i < t1.size(); i++)
        cur += t1[i];

    j--;
    double ans = p - cur;
    for (; i < t1.size() && j >= 0; i++, j--)
    {
        p /= t0[j] / 10.0;
        cur += t1[i];
        ans = min(ans, p - cur);
    }
    cout << max(0.0, ans) << '\n';

}

int main()
{
    cout << fixed << setprecision(2);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}