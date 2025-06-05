// https://www.luogu.com.cn/problem/P3370
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int bas1 = 131;
const int bas2 = 131;
const int mod = 1e9 + 7;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    set<pair<int, int>> ss;
    int n;
    cin >> n;

    auto has1 = [&](string &s)
    {
        int res = 0;
        for (auto &c : s)
        {
            res = (res * bas1 + c) % mod;
        }
        return res;
    };
    auto has2 = [&](string &s)
    {
        int res = 0;
        for (auto &c : s)
        {
            res = (res * bas2 + c) % mod;
        }
        return res;
    };

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        ss.insert({has1(s), has2(s)});
    }
    cout << ss.size();

    return 0;
}