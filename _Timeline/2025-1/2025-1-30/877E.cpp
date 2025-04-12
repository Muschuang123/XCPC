#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/**
 * 按照dfs序把树拆开，存住一个子树在区间上的左端点和右端点。
 * 线段树本质维护了一个时间戳序列，我们知道每个节点对应这哪个时间段。(in, out)
 */

const int maxn = 2e5 + 5;

int n;
vector<int> g[maxn];
int in[maxn], out[maxn];
// int sta[maxn];
int tim = 0;

void dfs(int x, int fa)
{
    in[x] = ++tim;
    for (auto &v : g[x])
    {
        if (v != fa)
            dfs(v, x);
    }
    out[x] = tim;
}

struct SegTree
{
    int l, r;
    ll v, add;
} t[maxn << 2 + 1];

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].v = 0;
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}

void spread(int p)
{
    if (t[p].add)
    {
        t[p << 1].v = t[p << 1].r - t[p << 1].l + 1 - t[p << 1].v;
        t[p << 1 | 1].v = t[p << 1 | 1].r - t[p << 1 | 1].l + 1 - t[p << 1 | 1].v;
        t[p << 1].add ^= 1;
        t[p << 1 | 1].add ^= 1;
        t[p].add = 0;
    }
}

void change(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].v = t[p].r - t[p].l + 1 - t[p].v;
        t[p].add ^= 1;
        return;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        change(p << 1, l, r);
    if (r > mid)
        change(p << 1 | 1, l, r);
    t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}

int ask(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        return t[p].v;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += ask(p << 1, l, r);
    if (r > mid)
        ans += ask(p << 1 | 1, l, r);
    return ans;

}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int ance;
        cin >> ance;
        g[ance].push_back(i);
    }

    dfs(1, 0);
    build(1, 1, n);

    for (int i = 1; i <= n; i++)
    {
        // cin >> sta[i];
        bool x;
        cin >> x;
        if (x)
            change(1, in[i], in[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        string op;
        int v;
        cin >> op >> v;
        if (op == "pow")
        {
            change(1, in[v], out[v]);
        }
        else
        {
            cout << ask(1, in[v], out[v]) << '\n';
        }
        
    }

    return 0;
}