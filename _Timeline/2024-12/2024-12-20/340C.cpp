#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());
    
    int sum = 0;
    for (int i = 1; i < n; i++)
        sum += (a[i + 1] - a[i]) * i * (n - i) * 2;
    sum += accumulate(a.begin() + 1, a.end(), 0LL);
    cout << sum / gcd(sum, n) << ' ' << n / gcd(sum, n) << '\n';
    

    return 0;
}