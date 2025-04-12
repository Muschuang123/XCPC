#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = 7;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1 || a[i] == 2 || a[i] == 3 || a[i] == 5 || a[i] == 6)
            continue;
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}