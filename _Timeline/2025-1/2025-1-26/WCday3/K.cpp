#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n + 1);
    int all = 0;
    for (int i = 1; i <= n; i++)
    {
        int len;
        cin >> len;
        all += len;
        while (len--)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    sort(a.begin() + 1, a.end());

    vector<pair<int, int>> v(1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            v.emplace_back(a[i][j], i);
        }
    }

    auto win = [&]()
    {
        cout << "Yes\n";
        for (int i = 1; i <= all; i++)
        {
            cout << v[i].first << ' ';
        }
        exit(0);
    };

    int inv = 0;
    for (int i = 1; i <= all; i++)
    {
        for (int j = i + 1; j <= all; j++)
        {
            if (v[j].first < v[i].first)
                inv++;
        }
    }

    if (k < inv)
    {
        cout << "No\n";
        return 0;
    }
    if (k == inv)
    {
        win();
    }

    for (int i = 1; i <= all; i++)
    {
        for (int j = all; j > i; j--)
        {
            if (v[j - 1].first < v[j].first && v[j - 1].second != v[j].second)
            {
                swap(v[j - 1], v[j]);
                inv++;
            }
            if (k == inv)
                win();
        }
    }

    cout << "No\n";

    return 0;
}