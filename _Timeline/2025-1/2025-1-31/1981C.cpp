#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 毒瘤题。。一百行构造，知道咋做写半天，调半天。
 */

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            q.push(i);
        }
    }

    if (q.size() == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i % 2 + 1 << " \n"[i == n];
        }
        return;
    }

    int le = q.front(), re = q.back();

    int l = 0, r = 0;

    while (q.size() >= 2)
    {
        l = q.front();
        q.pop();
        r = q.front();
        while (l + 1 < r)
        {
            if (a[l] > a[r])
            {
                l++;
                a[l] = a[l - 1] == 1 ? 2 : a[l - 1] >> 1;
            }
            else
            {
                r--;
                a[r] = a[r + 1] == 1 ? 2 : a[r + 1] >> 1;
            }
        }
    }
    
    for (int i = le - 1; i >= 1; i--)
    {
        if (a[i + 1] > 1)
            a[i] = a[i + 1] >> 1;
        else 
            a[i] = a[i + 1] << 1;
    }

    for (int i = re + 1; i <= n; i++)
    {
        if (a[i - 1] > 1)
            a[i] = a[i - 1] >> 1;
        else 
            a[i] = a[i - 1] << 1;
    }

    // checker
    for (int i = 1; i <= n - 1; i++)
    {
        if (a[i] != a[i + 1] / 2 && a[i] / 2 != a[i + 1])
        {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " \n"[i == n];
    }

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