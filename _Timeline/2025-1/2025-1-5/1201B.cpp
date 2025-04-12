#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin() + 1, a.end(), greater<>());
    int ok = sum % 2 == 0 && a[1] <= sum - a[1];
    
    cout << (ok ? "YES" : "NO");

    return 0;
}