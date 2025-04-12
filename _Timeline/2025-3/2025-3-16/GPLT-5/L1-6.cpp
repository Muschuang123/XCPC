#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    s = " " + s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        string cp = s.substr(l, r - l + 1);
        s.erase(l, r - l + 1);
        string sl, sr;
        cin >> sl >> sr;
        int x = sl.size();
        sl += sr;
        int len = sl.size();
        for (int i = 1; i + len - 1 < s.size(); i++)
        {
            if (s.substr(i, len) == sl)
            {
                s.insert(i + x, cp);
                goto E;
            }
        }
        s += cp;
E:;
    }
    cout << s.substr(1) << '\n';

    return 0;
}