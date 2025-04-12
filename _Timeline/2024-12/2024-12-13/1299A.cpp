#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> b[50];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (a[i] >> j & 1)
                b[j].push_back(i);
        }
    }

    vector<int> cnt(n + 1);
    // vector<pair<int, int>> res;
    for (int i = 0; i < 50; i++)
    {
        if (b[i].size() == 1)
            cnt[b[i].back()] += 1 << i;
    }

    // int mx = *max_element(cnt.begin() + 1, cnt.end());
    // for (int i = 1; i <= n; i++)
    // {
    //     if (cnt[i] == mx)
    //         res.push_back({a[i], i});
    // }
    // sort(res.begin(), res.end(), greater<pair<int, int>>());

    int ind = max_element(cnt.begin() + 1, cnt.end()) - cnt.begin();

    cout << a[ind] << ' ';
    for (int i = 1; i <= n; i++)
    {
        if (i != ind)
            cout << a[i] << ' ';
    }

    return 0;
}