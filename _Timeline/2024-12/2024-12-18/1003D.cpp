#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(64);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        int j = 0;
        while (x)
        {
            if (x & 1)
            {
                a[j]++;
                break;
            }
            x >>= 1;
            j++;
        }
    }

    vector<int> b = a;
    while (q--)
    {
        a = b;

        int x;
        cin >> x;

        int dig = 0;
        int ans = 0;
        bool ok = 1;
        while (x)
        {
            if (x & 1)
            {
                if (a[dig] == 0)
                {
                    int p = dig - 1;
                    int need = 1 << dig;
                    while (p >= 0)
                    {
                        if (need > a[p] * (1 << p))
                        {
                            need -= a[p] * (1 << p);
                            ans += a[p];
                            a[p] = 0;
                            p--;
                        }
                        else
                        {
                            ans += need / (1 << p);
                            a[p] -= need / (1 << p);
                            ok = 1;
                            break;
                        }
                    }
                    if (p < 0)
                        ok = 0;
                }
                else
                {
                    ans++;
                    a[dig]--;
                    ok = 1;
                }
            }
            if (!ok)
                break;
            x >>= 1;
            dig++;
        }
        if (ok)
            cout << ans << '\n';
        else 
            cout << -1 << '\n';
    }

    return 0;
}