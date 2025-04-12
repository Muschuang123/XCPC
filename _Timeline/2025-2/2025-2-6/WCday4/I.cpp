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
    string b = "uwawauwa";
    int nb = b.size();
    int cu = 0;
    int ans = 0;
    for (int i = 1; i + nb - 1 <= n; i++)
    {
        if (i >= 3)
            cu += s[i - 2] == 'u';
        if (cu && s.substr(i, nb) == b)
        {
            ans += cu;
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