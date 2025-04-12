#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    multiset<int> ss;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ss.insert(a[i]);
    }

    l = r = min_element(a.begin() + 1, a.end()) - a.begin();
    auto tit = ss.find(a[l]);
    int tmp = 2 * *tit;
    ss.erase(tit);
    ss.insert(tmp);

    int ans = *--ss.end() - *ss.begin();

    for (int i = 2; i <= n; i++)
    {
        if (l == 1)
        {
            auto it = ss.find(a[r + 1]);
            int t = 2 * *it;
            ss.erase(it);
            ss.insert(t);
            r++;
        }
        else if (r == n)
        {
            auto it = ss.find(a[l - 1]);
            int t = 2 * *it;
            ss.erase(it);
            ss.insert(t);
            l--;
        }
        else if (a[r + 1] < a[l - 1])
        {
            auto it = ss.find(a[r + 1]);
            int t = 2 * *it;
            ss.erase(it);
            ss.insert(t);
            r++;
        }
        else
        {
            auto it = ss.find(a[l - 1]);
            int t = 2 * *it;
            ss.erase(it);
            ss.insert(t);
            l--;
        }
        ans = min(ans, *--ss.end() - *ss.begin());
    }
    cout << ans;
    
    return 0;
}