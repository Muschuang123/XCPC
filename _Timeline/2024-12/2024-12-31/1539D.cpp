#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    the best choice is buy the item whose b[i] is biggest.
            (becuz it is most cant be discount finally)
        until the sum of ur bought items is more than smallest b[i].
    and then u just buy the smallest b[i] items by 1 ruble for a[i] times. 

    repeat the process, until the smallest b[i] item is the biggest b[i] item.
    
    finally calculate the min money u cost for it. (pay attention for can't discount)
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    multiset<pair<int, int>> ss;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> x;
        cin >> x.second >> x.first;
        ss.insert(x);
    }

    int ans = 0;
    int sum = 0;
    while (ss.size() > 1)
    {
        while (ss.size() > 1 && sum < ss.begin()->first)
        {
            pair<int, int> mx = *--ss.end();
            ss.erase(--ss.end());
            int need = min(ss.begin()->first - sum, mx.second);
            mx.second -= need;
            sum += need;
            ans += need * 2;
            if (mx.second != 0)
            {
                ss.insert(mx);
            }
        }
        while (ss.size() && sum >= ss.begin()->first)
        {
            ans += ss.begin()->second;
            sum += ss.begin()->second;
            ss.erase(ss.begin());
        }
    }

    if (ss.size())
    if (sum >= ss.begin()->first)
    {
        ans += ss.begin()->second;
    }
    else
    {
        int need = min(ss.begin()->second, ss.begin()->first - sum);
        ans += ss.begin()->second + need;
    }
    
    cout << ans;

    return 0;
}