#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    i64 ans = 0;
    i64 v = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            v += 10;
            ans += v;
        }
        if (s[i] == '1')
        {
            v = max(0LL, v - 5);
            ans += v;
        }
        if (s[i] == '2')
        {
            ans += max(0LL, v - 10);
        }
    }
    cout << ans << '\n';

    return 0;
}