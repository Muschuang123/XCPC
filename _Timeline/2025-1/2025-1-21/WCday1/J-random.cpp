#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = rand() % 100 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << rand() % 100 + 1 << " \n"[i == n];
    }

    return 0;
}