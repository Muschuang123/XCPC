// https://zhuanlan.zhihu.com/p/675835378
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<string> ans[105];

void init()
{
    ans[1].push_back("1");
    ans[3].push_back("169");
    ans[3].push_back("196");
    ans[3].push_back("961");
    for (int i = 5; i <= 99; i += 2)
    {
        for (int j = 0; j < ans[i - 2].size(); j++)
        {
            ans[i].push_back(ans[i - 2][j] + "00");
        }
        string s(i, '0');
        s.front() = '1';
        s[s.size() / 2] = '6';
        s.back() = '9';
        ans[i].push_back(s);
        swap(s.front(), s.back());
        ans[i].push_back(s);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < ans[n].size(); i++)
    {
        cout << ans[n][i] << '\n';
    }
}

int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}