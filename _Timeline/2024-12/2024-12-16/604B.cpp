#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
vector<int> a;
vector<int> b;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    k = min(k, n);
    int res = n - k;
    for (int i = 1; i <= res; i++)
        b.push_back(a[i] + a[2 * res - i + 1]);
    for (int i = 2 * res + 1; i <= n; i++)
        b.push_back(a[i]);
    
    sort(b.begin(), b.end());
    cout << b.back();

    return 0;
}