#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a;
    int res = 0;
    for (int i = 0; i < min(x + 1, n) && (i | x) == x; i++)
    {
        a.push_back(i);
        res |= i;
    }

    for (int i = a.size(); i < n; i++)
        a.push_back(0);
    
    if (res != x)
    {
        a.pop_back();
        a.push_back(x);
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];
    
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