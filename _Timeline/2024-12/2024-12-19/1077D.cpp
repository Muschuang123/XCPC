#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 7;
int n, k;
vector<int> a(maxn);

bool check(int mid)
{
    int ans = 0;
    for (int i = 1; i <= 2e5; i++)
    {
        ans += a[i] / mid;
    }
    return ans >= k;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }

    int l = 0, r = 1e9 + 7;
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid;
    }

    

    vector<int> ans;
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = 1; j <= a[i] / l; j++)
        {
            ans.push_back(i);
            if (ans.size() == k)
            {
                for (auto &e : ans)
                {
                    cout << e << ' ';
                }
                return 0;
            }
        }
    }
    

    return 0;
}