#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            cout << ' ';
        int t = m, cnt = 0, res = 0;
        if (a[i])
            res++;
        else if (t > 0)
            res++, t--;
        int p = 1;
        while (res < k)
        {
            if (i - p >= 1)
            {
                if (a[i - p])
                    cnt += p, res++;
                else if (t > 0)
                    cnt += p, res++, t--;
            }
            if (res >= k)
                break;
            if (i + p <= n)
            {
                if (a[i + p])
                    cnt += p, res++;
                else if (t > 0)
                    cnt += p, res++, t--;
            }
            p++;
        }
        cout << cnt;
    }
    cout << '\n';
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