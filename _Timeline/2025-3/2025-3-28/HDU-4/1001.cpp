#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct mob
{
    int k, h, a, i;
};

bool operator<(const mob &a, const mob &b)
{
    return a.h < b.h || a.h == b.h && a.a < b.a ||
         a.h == b.h &&  a.a == b.a && a.i < b.i;
}

void solve()
{
    int n, u, tk, hq;
    cin >> n >> u >> tk >> hq;
    set<mob> ss;
    multiset<int> at;
    for (int i = 1; i <= n; i++)
    {
        int a, h;
        cin >> a >> h;
        ss.insert({0, h, a, i});
        at.insert(a);
    }

    int cnt = 0;
    while (ss.size())
    {
        auto [k, h, a, i] = *ss.begin();
        ss.erase(ss.begin());
        if (k)
        {
            h -= u / 2;
        }
        else
        {
            h -= u;
        }
        k++;
    
        if (h <= 0)
        {
            at.extract(a);
            cnt++;
        }
        else if (k < tk)
        {
            ss.insert({k, h, a, i});
        }
        if (at.size())
            hq -= *at.rbegin();
        if (hq <= 0)
            break;
    }
    cout << cnt << '\n';
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