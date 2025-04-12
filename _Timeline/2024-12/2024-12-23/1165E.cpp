#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i] * i * (n - i + 1);
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end(), greater<int>());

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + a[i] % mod * b[i] % mod) % mod;
    }
    cout << sum;


    return 0;
}