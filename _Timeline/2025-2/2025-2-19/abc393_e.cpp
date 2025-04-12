#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector<int> b(1e6 + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }

    vector<int> ans(1e6 + 1);
    for (int i = 1; i <= 1e6; i++)
    {
        int cnt = 0;
        for (int j = i; j <= 1e6; j += i)
        {
            cnt += b[j];
        }
        if (cnt >= k)
        {
            for (int j = i; j <= 1e6; j += i)
            {
                ans[j] = max(ans[j], i);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[a[i]] << '\n';
    }

    return 0;
}