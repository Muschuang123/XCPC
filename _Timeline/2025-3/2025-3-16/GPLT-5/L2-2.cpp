#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int x;
        cin >> x;
        int res = (x + c - 1) / c;
        cnt += x / c;
        a[i] = x % c;
        cout << s << ' ' << res << '\n';
    }
    sort(a.begin() + 1, a.end(), greater<>());
    multiset<int> t;
    for (int i = 1; i <= n && a[i] != 0; i++)
    {
        auto it = t.lower_bound(a[i]);
        if (it == t.end())
        {
            t.insert(c - a[i]);
        }
        else 
        {
            int tt = *it;
            t.erase(it);
            t.insert(tt - a[i]);
        }
    }
    cout << cnt + t.size();

    return 0;
}