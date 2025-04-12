#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1); 
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << *max_element(a.begin() + 1, a.end()) - *min_element(a.begin() + 1, a.end()) << '\n';
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