#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    map<int, int> row, col;
    for (int i = 1; i <= d; i++)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p)
        {
            if (y > q)
                swap(y, q);
            row[y]++;
        }
        if (y == q)
        {
            if (x > p)
                swap(x, p);
            col[x]++;
        }
    }

    vector<pair<int, int>> hh, lx;
    for (auto &[f, s] : row)
    {
        lx.push_back({s, f});
    }
    for (auto &[f, s] : col)
    {
        hh.push_back({s, f});
    }
    sort(hh.begin(), hh.end(), greater<>());
    sort(lx.begin(), lx.end(), greater<>());
    vector<int> ans1, ans2;
    for (int i = 0; i < k; i++)
        ans1.push_back(hh[i].second);
    for (int i = 0; i < l; i++)
        ans2.push_back(lx[i].second);
    
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    for (auto &e : ans1)
    {
        cout << e << ' ';
    }
    cout << '\n';
    for (auto &e : ans2)
    {
        cout << e << ' ';
    }
    cout << '\n';

    return 0;
}