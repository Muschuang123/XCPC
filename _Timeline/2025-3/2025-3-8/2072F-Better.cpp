#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// Lucas

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cout << ((n - 1 & i - 1) == i - 1) * k << " \n"[i == n];
    }
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