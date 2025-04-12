#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int l, r, i, ans;
};

bool operator<(const node &a, const node &b)
{
    return a.l > b.l || a.l == b.l && a.r > b.r;
}

bool cmpc(const node &a, const node &b)
{
    return a.r < b.r || a.r == b.r && a.l < b.l;
}

bool cmp(const node &a, const node &b)
{
    return a.i < b.i;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
        a[i].i = i;
        a[i].ans = 0;
    }
    sort(a.begin() + 1, a.end(), cmpc);
    priority_queue<node> q;
    int cur = 1;
    vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (q.size() && cur >= q.top().l)
        {
            node x = q.top();
            q.pop();
            if (cur > x.r)
            {
                cout << -1 << '\n';
                return 0;
            }
            t[x.i] = cur++;
        } 
        
        if (cur >= a[i].l && cur <= a[i].r)
        {
            a[i].ans = cur++;
            continue;
        }
        if (cur > a[i].r)
        {
            cout << -1 << '\n';
            return 0;
        }
        if (cur < a[i].l)
        {
            q.push(a[i]);
        }
    }

    while (q.size() && cur >= q.top().l)
    {
        node x = q.top();
        q.pop();
        if (cur > x.r)
        {
            cout << -1 << '\n';
            return 0;
        }
        t[x.i] = cur++;
    }

    if (q.size())
    {
        cout << -1 << '\n';
        return 0;
    }

    sort(a.begin() + 1, a.end(), cmp);

    for (int i = 1; i <= n; i++)
    {
        if (a[i].ans == 0)
        {
            cout << t[i] << ' ';
        }
        else
        {
            cout << a[i].ans << ' ';
        }
    }
    cout << '\n';

    return 0;
}