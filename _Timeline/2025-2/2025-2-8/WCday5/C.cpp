#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 n, x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    vector<i64> ca(5);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1' && b[i] == '1' && c[i] == '1')
            ca[1]++;
        if (a[i] == '0' && b[i] == '0' && c[i] == '1')
            ca[2]++;
        if (a[i] == '1' && b[i] == '0' && c[i] == '0')
            ca[3]++;
        if (a[i] == '0' && b[i] == '1' && c[i] == '0')
            ca[4]++;
    }

    if (2 * x <= y)
    {
        cout << x * accumulate(ca.begin() + 1, ca.end(), 0LL) << '\n';
    }
    else
    {
        i64 ans = 0;
        sort(ca.begin() + 1, ca.end(), greater<>());
        // while (ca[2] >= 1)
        // {
        //     i64 mi = min(ca[1], ca[2]);
        //     ca[1] -= mi;
        //     ca[2] -= mi;
        //     ans += mi * y;
        //     sort(ca.begin() + 1, ca.end(), greater<>());
        // }
        // ans += x * accumulate(ca.begin() + 1, ca.end(), 0LL);
        
        /**
         * HACKED BY:
         * 
            10 5 6
            1100001010
            1100101101
            0111101010
         */
        if (ca[1] > ca[2] + ca[3] + ca[4])
        {
            int need = ca[2] + ca[3] + ca[4];
            ca[1] -= need;
            ans = need * y + ca[1] * x;
        }
        else
        {
            int sum = ca[1] + ca[2] + ca[3] + ca[4];
            ans = sum / 2 * y + sum % 2 * x;
        }
        cout << ans << '\n';
    }
    
    return 0;
}