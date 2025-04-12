#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    
    vector<int> a(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i] - '0';
        a[i] %= 3;
        if (a[i] == 0)
            vis[i] = 1;
    }

    int cur = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            cur = 0;
            ans++;
            cnt = 0;
            continue;
        }
        
        cnt++;
        cur = (cur + a[i]) % 3;
        if (cur == 0 || cnt == 3)
        {
            cur = 0;
            ans++;
            cnt = 0;
        }
    }
    cout << ans;

    return 0;
}