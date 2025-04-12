#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    a.push_back(0);
    int pos;
    cin >> pos;

    int p = n;
    vector<pair<int, pair<int, char>>> del(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i + 1])
        {
            int l = i, r = i + 1;
            while (l >= 1 && a[l] > a[r])
            {
                if (del[l].first == 0)
                {
                    del[l].first = p--;
                    del[l].second.first = l;
                    del[l].second.second = a[l];
                }
                l--;
            }
        }
    }

    sort(del.begin() + 1, d el.end());

    int r = 0, len = 0;
    for (int i = n; i >= 1; i--)
    {
        r += i;
        if (r >= pos)
        {
            pos -= r - i;
            len = i;
            break;
        }
    }

    vector<pair<int, char>> res;
    for (int i = 1; i <= len; i++)
    {
        res.push_back(del[i].second);
    }

    sort(res.begin(), res.end());
    cout << res[pos - 1].second;

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