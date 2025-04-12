#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    寻找相同数字构成的区间。如果当前位置不被区间覆盖，就有一个贡献。
    答案是 2^(贡献)。

    相对于上一个做法，这个只关注每种数字的最右端 在哪里。
    省略了开图的空间。
*/

const int mod = 998244353;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }

    int r = 1;
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i > r)
        {
            ans *= 2;
            ans %= mod;
        }
        r = max(r, mp[a[i]]);
    }
    cout << ans;

    return 0;
}