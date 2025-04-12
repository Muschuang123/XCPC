#include <bits/stdc++.h>
#define int long long
using namespace std;

/**
 * 别喷史山，史山能过。
 * std 是优化后简短的史山。
 */

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    return a.first.size() < b.first.size();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> a(2 * n - 2 + 1);
    vector<char> ans(2 * n - 2 + 1);
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin() + 1, a.end(), cmp);
    
    string t1, t2;
    int fl = 1, cnt = 1;

    // try the first
    t1 = a[1].first;
    t2 = a[2].first;
    ans[1] = 'P';
    ans[2] = 'S';
    for (int i = 3; i <= 2 * n - 2 + 1; i += 2)
    {
        if (cnt < (i - 1) / 2)
        {
            fl = 0;
            break;
        }
        if (i <= 2 * n - 2)
        {
            if (t1 == a[i].first.substr(0, t1.size()) && t2 == a[i + 1].first.substr(1, t2.size()))
            {
                t1 = a[i].first;
                t2 = a[i + 1].first;
                ans[i] = 'P';
                ans[i + 1] = 'S';
                cnt = (i + 1) / 2;
            }
            else
            {
                swap(a[i], a[i + 1]);
                if (t1 == a[i].first.substr(0, t1.size()) && t2 == a[i + 1].first.substr(1, t2.size()))
                {
                    t1 = a[i].first;
                    t2 = a[i + 1].first;
                    ans[i] = 'P';
                    ans[i + 1] = 'S';
                    cnt = (i + 1) / 2;
                }
            }
        }
    }

    if (!fl)
    {
        ans.clear();
        ans.resize(2 * n - 2 + 1);
        string t = a[2].first;
        ans[2] = 'P';
        for (int i = 3; i <= 2 * n - 2; i++)
        {
            if (t == a[i].first.substr(0, t.size()))
            {
                t = a[i].first;
                ans[i] = 'P';
                i += i % 2;
            }
        }
        for (int i = 1; i <= 2 * n - 2; i++)
        {
            if (ans[i] != 'P')
                ans[i] = 'S';
        }
    }

    vector<char> res(2 * n - 2 + 1);
    for (int i = 1; i <= 2 * n - 2; i++)
    {
        res[a[i].second] = ans[i];
    }

    for (int i = 1; i <= 2 * n - 2; i++)
        cout << res[i];

    return 0;
}