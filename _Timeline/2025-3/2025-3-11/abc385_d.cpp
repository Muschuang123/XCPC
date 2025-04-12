#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    i64 sx, sy;
    cin >> n >> m >> sx >> sy;
    set<pair<i64, i64>> row, col;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        row.insert({x, y});
        col.insert({y, x});
    }

    int ans = 0;
    const i64 inf = 1e9 + 7;
    while (m--)
    {
        char d;
        i64 c;
        cin >> d >> c;
        set<pair<i64, i64>>::iterator st, en;
        int rv = 0;
        if (d == 'R')
        {
            rv = 1;
            st = col.lower_bound({sy, sx});
            en = col.upper_bound({sy, sx + c});
            sx += c;
        }
        else if (d == 'L')
        {
            rv = 1;
            st = col.lower_bound({sy, sx - c});
            en = col.upper_bound({sy, sx});
            sx -= c;
        }
        else if (d == 'D')
        {
            st = row.lower_bound({sx, sy - c});
            en = row.upper_bound({sx, sy});
            sy -= c;
        }
        else if (d == 'U')
        {
            st = row.lower_bound({sx, sy});
            en = row.upper_bound({sx, sy + c});
            sy += c;
        }

        vector<pair<i64, i64>> del;
        for (; st != en; st++)
        {
            i64 x = st->first, y = st->second;
            if (rv)
                swap(x, y);
            del.emplace_back(x, y);
            ans++;
        }
        for (auto &[x, y] : del)
        {
            row.erase({x, y});
            col.erase({y, x});
        }
    }

    cout << sx << ' ' << sy << ' ' << ans << '\n';

    return 0;
}