#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N = 1000 + 10;
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;

struct node
{
    int x, y;
} a[maxn];

bool cmp(node a, node b)
{
    if (a.x == b.x)
        return a.y > b.y;
    return a.x < b.x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].x = a[i].x - i, a[i].y = a[i].y - i;
    }
    sort(a + 1, a + 1 + n, cmp);
    multiset<int> s;

    for (int i = 1; i <= n; i++)
    {
        int y = a[i].y;
        auto it = s.lower_bound(y);

        if (it == s.end())
        {
            s.insert(y);
            continue;
        }
        else
        {
            vector<int> t;
            for (; it != prev(s.end()); it++)
                t.push_back(*it);
            for (auto i : t)
                s.extract(i);
        }
    }
    cout << s.size() << endl;
}