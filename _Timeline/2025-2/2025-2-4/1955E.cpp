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
    int n0 = count(s.begin() + 1, s.end(), '0');
    if (n0 == n || n0 == 0)
    {
        cout << n << '\n';
        return;
    }

    int ans = 0;
    string cp = s;

    for (int len = 1; len <= n; len++)
    {
        s = cp;
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            while (q.size() && q.front() < i)
                q.pop();
            if (q.size() % 2)
            {
                s[i] = s[i] == '1' ? '0' : '1';
            }
            if (s[i] == '0')
                q.push(i + len - 1);
        }
        while (q.size() && q.front() <= n)
            q.pop();
        if (q.empty())
            ans = max(ans, len);
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