#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    int fl0 = 0, fl1 = 0;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            cnt++;
        if (s.substr(i, 2) == "11")
            fl1++;
        if (s.substr(i, 2) == "00")
            fl0++;
    }

    cnt += min(2LL, fl0 + fl1);
    
    cout << cnt;

    return 0;
}