#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    int pos;
    cin >> pos;
    int len = 0;
    for (int i = n; i >= 1; i--)
    {
        int seg = i;
        if (pos <= seg)
        {
            // 需要删掉的长度
            len = n - i;
            break;
        }
        pos -= seg;
    }

    string t;
    for (int i = 1; i <= n; i++)
    {
        // 单调栈，删去 len 个字符。
        while (len > 0 && t.size() && t.back() > s[i])
        {
            t.pop_back();
            len--;
        }
        t.push_back(s[i]);
    }
    
    cout << t[pos - 1];

}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}