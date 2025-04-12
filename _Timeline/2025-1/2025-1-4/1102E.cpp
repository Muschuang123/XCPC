#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int ksm(int a, int n)
{
    int ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

queue<int> g[200005];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, int> mp;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!mp.count(a[i]))
            mp[a[i]] = ++cnt;
        a[i] = mp[a[i]];
        g[a[i]].push(i);
    }

    set<int> ss;
    ss.insert(1);

    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ss.empty())
        {
            len++;
        }

        ss.insert(a[i]);
        g[a[i]].pop();
        if (g[a[i]].empty())
            ss.erase(a[i]);
    }

    cout << ksm(2, len);

    return 0;
}