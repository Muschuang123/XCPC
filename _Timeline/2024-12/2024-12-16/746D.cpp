#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    if ((b + k - 1) / k > a + 1 || (a + k - 1) / k > b + 1)
    {
        cout << "NO";
        return 0;
    }
    if (a >= b)
    {
        int uh = a / (b + 1);
        int res = a % (b + 1);
        while (res--)
        {
            for (int i = 1; i <= uh + 1; i++)
            {
                cout << 'G';
                a--;
            }
            cout << 'B';
            b--;
        }
        while (b > 0)
        {
            for (int i = 1; i <= uh; i++)
            {
                cout << 'G';
                a--;
            }
            cout << 'B';
            b--;
        }
        for (int i = 1; i <= uh; i++)
        {
            cout << 'G';
            a--;
        }
    }
    else
    {
        int uh = b / (a + 1);
        int res = b % (a + 1);
        while (res--)
        {
            for (int i = 1; i <= uh + 1; i++)
            {
                cout << 'B';
                b--;
            }
            cout << 'G';
            a--;
        }
        while (a > 0)
        {
            for (int i = 1; i <= uh; i++)
            {
                cout << 'B';
                b--;
            }
            cout << 'G';
            a--;
        }
        for (int i = 1; i <= uh; i++)
        {
            cout << 'B';
            b--;
        }
    }
    

    return 0;
}