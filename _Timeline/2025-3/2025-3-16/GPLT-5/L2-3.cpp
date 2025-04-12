#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> in(n, vector<int>((1 << n - 1) + 1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= (1 << i); j++)
        {
            cin >> in[i][j];
        }
    }

    // size == (1 << n)
    vector<int> a(1);
    cin >> a[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= (1 << i); j++)
        {
            a.push_back(in[i][j]);
        }
    }
    vector<int> mx(1 << n);
    for (int i = (1 << n) - 1; i >= 1; i--)
    {
        if (i < (1 << n - 1))
            mx[i] = max({a[i], mx[i << 1], mx[i << 1 | 1]});
        else 
            mx[i] = a[i];
    }

    vector<int> ans;
    function<void(int, int)> dfs = [&](int x, int p)
    {
        if (p < a[x])
        {
            cout << "No Solution";
            exit(0);
        }

        if (x >= (1 << n - 1))
        {
            ans.push_back(a[x]);
            ans.push_back(p);
            return;
        }
        if (a[x] >= mx[x << 1] && p >= mx[x << 1 | 1])
        {
            dfs(x << 1, a[x]);
            dfs(x << 1 | 1, p);
        }
        else if (p >= mx[x << 1] && a[x] >= mx[x << 1 | 1])
        {
            dfs(x << 1, p);
            dfs(x << 1 | 1, a[x]);
        }
        else
        {
            cout << "No Solution";
            exit(0);
        }
    };
    dfs(1, a[0]);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)  
            cout << ' ';
        cout << ans[i];
    }

    return 0;
}