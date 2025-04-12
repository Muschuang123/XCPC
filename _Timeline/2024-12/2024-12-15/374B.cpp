#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';
    int cnt = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != 9 && a[i] + a[i - 1] == 9)
        {
            cnt++;
        }
        else
        {
            if (cnt % 2 == 1)
            {
                ans *= (cnt + 1) / 2;
            }
            cnt = 1;
        }
    }
    
    if (cnt % 2 == 1)
    {
        ans *= (cnt + 1) / 2;
    }

    cout << ans;

    return 0;
}