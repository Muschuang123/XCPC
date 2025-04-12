#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    use the map to save the prefix sum. 
    initally, mp[0] = 1. 
    for the i from 1 to n: ans += mp[prefix_sum[i]]
        after this, mp[prefix_sum[i]]++.
    
    in this map, it shows how many segments's prefix_sum is same. 
    if some prefix_sum are same, their difference subarray are the answer.
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        a[i] = tmp - '0' - 1;
        s[i] = s[i - 1] + a[i];
    }

    int ans = 0;

    map<int, int> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        // if (a[i] != -1)
        // {
            ans += mp[s[i]];
        // }
        mp[s[i]]++;
        cout << "";
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}