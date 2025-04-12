#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += i * i;

    vector<int> con;
    for (int i = 0; i <= 1e4; i++)
    {
        con.push_back(i * (i + 1) / 2);
    }
    
    if (sum > k)
    {
        cout << -1 << '\n';
        return 0;
    }
    
    vector<int> ans(n + 1);
    ans[n] = n;
    while (sum < k)
    {
        sum += n * (n + 1) / 2;
        ans[n]++;
    }

    vector<int> res(1e4 + 1);
    sum -= k;
    while (sum > 0)
    {
        int idx = --upper_bound(con.begin(), con.end(), sum) - con.begin();
        res[idx]++;
        sum -= con[idx];
    }

    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = ans[i + 1] - res[i] - 1;
    }
    if (ans[1] <= 0)
    {
        cout << -1 << '\n';
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " \n"[i == n];
        }
    }
    

    return 0;
}