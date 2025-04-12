#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Median
{
    multiset<int> s1, s2;

    void balance()
    {
        int sz1 = s1.size(), sz2 = s2.size();
        if (sz2 > sz1 + 1)
        {
            int now = *s2.begin();
            s1.insert(now);
            s2.erase(s2.begin());
        }
        else if (sz1 > sz2)
        {
            int now = *s1.rbegin();
            s2.insert(now);
            s1.erase(prev(s1.end()));
        }
    }

    void insert(int x)
    {
        if (s2.empty())
        {
            s2.insert(x);
        }
        else
        {
            int num = *s2.begin();
            if (x >= num)
                s2.insert(x);
            else
                s1.insert(x);
        }
        balance();
    }

    void erase(int x)
    {
        if (s1.count(x))
            s1.erase(s1.find(x));
        else
            s2.erase(s2.find(x));
        balance();
    }

    int query()
    {
        return *s2.begin();
    }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    Median mid;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mid.insert(x);
        if (i % 2)
            cout << mid.query() << '\n';
    }

    return 0;
}