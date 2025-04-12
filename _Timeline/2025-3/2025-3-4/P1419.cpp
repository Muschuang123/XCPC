#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 让所有数都减去一个数，这个方法可以用来求平均值。
// 二分减去的这个数，直到 使得 len∈[s, t] 的最大子段和 >= 0

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, s, t;
    cin >> n >> s >> t;
    vector<double> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    auto check = [&](double mid)
    {
        vector<double> b = a;
        for (int i = 1; i <= n; i++)
            b[i] -= mid;
        double ans = -1;
        double mn = 0;
        multiset<double> ss;
        for (int i = 1; i <= n; i++)
        {
            b[i] += b[i - 1];
            if (i - s >= 0)
                ss.insert(b[i - s]);
            if (i - t - 1 >= 0)
                ss.extract(b[i - t - 1]);
            if (!ss.empty())
                ans = max(ans, b[i] - *ss.begin());
        }

        return ans >= 0;
    };
    
    double l = 0, r = *max_element(a.begin() + 1, a.end()) + 1;
    while (l + 1e-5 < r)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else 
            r = mid;
    }

    cout << fixed << setprecision(3) << l;

    return 0;
}