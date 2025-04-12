#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    i64 ans = 0;

    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            int len = r - l + 1;
            string t = s.substr(l, len);
            int res = 0;
            for (int i = 0; i < len; i++)
            {
                if (t[i] == '1')
                {
                    res++;
                    i += 2;
                }
            }
            ans += res;
        }
    }
    cout << ans << '\n';
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