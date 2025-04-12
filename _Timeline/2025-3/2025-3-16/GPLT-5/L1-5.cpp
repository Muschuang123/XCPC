#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int tt;
    cin >> tt;
    while (tt--)
    {
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) cin >> b[i];
        if (count(b.begin() + 1, b.end(), 0) == n)
        {
            cout << "Ai Ya\n";
            goto E;
        }
        for (int i = 1; i <= n; i++)
        {
            if (b[i] == 0)
                continue;
            if (b[i] != a[i])
            {
                cout << "Ai Ya\n";
                goto E;
            }
        }
        cout << "Da Jiang!!!\n";
E:;
    }

    return 0;
}