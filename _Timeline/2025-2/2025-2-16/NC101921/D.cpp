#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        priority_queue<int, vector<int>, greater<>> q;
        for (int j = 1; j <= n; j++)
        {
            q.push(a[i][j]);
        }

        vector<int> vec;
        for (int j = 1; j <= i - 1; j++)
        {
            while (q.size() && (q.top() < a[i - 1][j - 1] || q.top() < a[i - 1][j]))
            {
                vec.push_back(q.top());
                q.pop();
            }
            if (q.empty())
            {
                cout << i - 1 << '\n';
                return;
            }
            a[i][j] = q.top();
            q.pop();
        }
        if (q.empty())
        {
            cout << i - 1 << '\n';
            return;
        }
        a[i][i] = q.top();
        q.pop();
    }
    cout << n << '\n';
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