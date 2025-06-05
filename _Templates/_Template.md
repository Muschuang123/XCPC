### 快速幂

```cpp
// 注意可能在 998244353 上挖坑
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
// 无 mod 版本
int ksm(int a, int n)
{
    int ans = 1;
    while (n) {
        if (n & 1)
            ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
```

### Dijkstra（BFS）

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge
{
    int v, w;
};

vector<edge> g[100005];
vector<bool> vis;
vector<int> d;

// 调用前需要初始化 vis, d, g
// 调用结束后更新 d
// s 点到其余点的最短路
void dijkstra(int s)
{
    d[s] = 0;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &c : g[x])
        {
            int v = c.v, w = c.w;
            if (d[v] > d[x] + w)
            {
                d[v] = d[x] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    vis.resize(n + 1);
    d.resize(n + 1, 0x3f3f3f3f);

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(s);
    for (int i = 1; i <= n; i++)
        cout << d[i] << " \n"[i == n];

    return 0;
}
```

### 并查集

```cpp
struct dsu
{
    int n, cnt;
    vector<int> fa, sz;

    // Index 0 is invalid
    dsu(int _n = 0)
    {
        n = _n - 1;
        cnt = n;
        fa.resize(n + 1);
        for (int i = 1; i <= n; i++)
            fa[i] = i;
        sz.resize(n + 1, 1);
    }

    int fin(int x)
    {
        if (fa[x] == x)
            return x;
        return fa[x] = fin(fa[x]);
    }

    bool merg(int u, int v)
    {
        u = fin(u), v = fin(v);
        if (u == v)
            return 0;
        if (sz[u] < sz[v])
            swap(u, v);
        fa[v] = u;
        sz[u] += sz[v];
        cnt--;
        return 1;
    }
};
```

### 拓扑排序

```cpp
// LuoGu B3644
#include <bits/stdc++.h>
using namespace std;

vector<int> g[102];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> rd(n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (1)
        {
            int x;
            cin >> x;
            if (!x)
                break;
            g[i].push_back(x);
            rd[x]++;
        }
    }
    queue<int> q;
    vector<bool> rem(n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (rd[i] == 0)
            q.push(i);
    }

    while (q.size())
    {
        int i = q.front();
        q.pop();
        if (rd[i] == 0 && rem[i])
        {
            for (auto &c : g[i])
            {
                if (--rd[c] == 0)
                q.push(c);
            }
            rem[i] = 0;
        }
        cout << i << ' ';
    }

    return 0;
}
```

### LCA 最近公共祖先

LuoGu P3379

```cpp
// LCA : 最近公共祖先 Lowest Common Ancestors
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, s;
vector<int> g[500005];
vector<vector<int>> fa;
vector<int> depth;
// vector<bool> vis;
vector<int> lg;

void dfs(int x, int father)
{
    depth[x] = depth[father] + 1;
    fa[x][0] = father;
    for (int i = 1; i <= lg[depth[x]]; i++)
    {
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }

    if (g[x].size() == 1 && x != s)
        return;
  
    // vis[x] = 1;
    for (auto &v : g[x])
    {
        if (v != father)
        {
            dfs(v, x);
        }
    }
    // vis[x] = 0;

}

int LCA(int x, int y)
{
    // 让 x 更深
    if (depth[x] < depth[y])
        swap(x, y);
    while (depth[x] > depth[y])
    {
        x = fa[x][lg[depth[x] - depth[y]]];
    }
    if (x == y)
        return x;
    for (int i = lg[depth[x]]; i >= 0; i--)
    {
        if(fa[x][i] != fa[y][i])
        {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> q >> s;
    // vis.clear();
    // vis.resize(n + 1);
    lg.clear();
    lg.resize(n + 1);
    // 取log_2对数，预处理
    for (int i = 1; i <= n; i++)
	    lg[i] = lg[i - 1] + (1 << lg[i - 1] == i); 
    for (int i = 1; i <= n; i++)
        lg[i]--;
    fa.clear();
    fa.resize(n + 1, vector<int>(25));
    depth.clear();
    depth.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(s, 0);

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
  

    return 0;
}
```

### 线段树的区间修改和查询

```cpp
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree
{
    int l, r, v, add;
};

vector<int> a;
vector<SegTree> t;

void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
    {
        t[p].v = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    // sum
    t[p].v = t[p << 1].v + t[p << 1 | 1].v;
}

void spread(int p)
{
    if (t[p].add)
    {
        t[p << 1].v += t[p].add * (t[p << 1].r - t[p << 1].l + 1);
        t[p << 1 | 1].v += t[p].add * (t[p << 1 | 1].r - t[p << 1 | 1].l + 1);
        t[p << 1].add += t[p].add;
        t[p << 1 | 1].add += t[p].add;
        t[p].add = 0;
    }
}

void change(int p, int l, int r, int d)
{
    if (l <= t[p].l && t[p].r <= r)
    {
        t[p].v += d * (t[p].r - t[p].l + 1);
        t[p].add += d;
        return;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid)
        change(p << 1, l, r, d);
    if (r > mid)
        change(p << 1 | 1, l, r, d);
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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    a.resize(n + 1);
    t.resize(4 * n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);
    while (m--)
    {
        int op, x, y, k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            change(1, x, y, k);
        }
        else
        {
            cin >> x >> y;
            cout << ask(1, x, y) << '\n';
        }
    
    }


    return 0;
}
```

### 树状数组

```cpp
// 树状数组
// 前缀和的单点修改与查询
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> s;

void add(int x, int y)
{
    while (x <= n)
    {
        s[x] += y;
        x += x & -x;
    }
}

int ask(int x)
{
    int ans = 0;
    while (x)
    {
        ans += s[x];
        x -= x & -x;
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m;
    cin >> n >> m;
    s.resize(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i]);
    }

    while (m--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            add(x, y);
        }
        if (op == 2)
        {
            cout << ask(y) - ask(x - 1) << '\n';
        }
    }

    return 0;
}
```

### 求逆序数

```cpp
// 在树状数组的数据结构下：
for (int i = n; i >= 1; i--)
{
    ans += ask(a[i] - 1);
    add(a[i], 1);
}
// 注意a[i]的大小，过大可以用map离散化
```

### 组合数

```cpp
i64 f[maxn], g[maxn];
i64 ksm(i64 a, i64 n)
{
    i64 ans = 1;
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

void init()
{
    f[0] = 1;
    g[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2) % mod;
    }
}

i64 C(i64 n, i64 m)
{
    if (m > n || n < 0 || m < 0)
        return 0;
    if (m == 0)
        return 1;
    return f[n] * g[m] % mod * g[n - m] % mod;
}
```

### 埃氏筛

```cpp
vector<int> prime;
bool is_prime[maxn];

void Eratosthenes(int n)
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            if (i * i > n)
                continue;
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

```

### 线性筛

```cpp
vector<int> pri;
bool not_prime[maxn];
int minp[maxn];
void primer(int n)
{
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!not_prime[i])
        {
            pri.push_back(i);
            minp[i] = i;
        }
        for (int j : pri)
        {
            if (i * j > n)
                break;
            not_prime[i * j] = true;
            minp[i * j] = j;
            if (i % j == 0)
                break;
        }
    }
}
```

### 字符串哈希

```cpp
// double hash to increase accuracy.
// 注意 1 号乘的 base 次数最多
vector<int> pre1(n + 1), pre2(n + 1);
for (int i = 1; i <= n; i++)
{
    pre1[i] = (pre1[i - 1] * bas1 + s[i]) % mod;
    pre2[i] = (pre2[i - 1] * bas2 + s[i]) % mod;
}
```

### 二分图判定

```cpp
int ok = 1;
vector<int> vis(n + 1, -1);
queue<int> q;
vis[1] = 0;
q.push(1);
while (q.size())
{
    int x = q.front();
    q.pop();
    for (auto &v : g[x])
    {
        if (vis[v] == -1)
        {
            q.push(v);
            vis[v] = vis[x] ^ 1;
        }
        else if (vis[x] == vis[v])
        {
            ok = 0;
            break;
        }
    }
    if (!ok)
        break;
}
```

### 扩展欧几里得（EXGCD）

```cpp
array<i64, 3> exgcd(i64 a, i64 b)
{
    if (b == 0)
    {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 inv(i64 a, i64 b)
{
    auto [g, x, y] = exgcd(a, b);
    return x > 0 && x % b != 0 ? x % b : x % b + b;
}

    // 这里min是只最小正整数解，所以max求出来有可能是负的，说明没有正整数解。
    // x 和 y 是此消彼长的关系。
    i64 minx = x > 0 && x % b != 0 ? x % b : x % b + b;
    i64 maxy = (c - a * minx) / b;
    i64 miny = y > 0 && y % a != 0 ? y % a : y % a + a;
    i64 maxx = (c - b * miny) / a;
```

### 中国剩余定理（CRT）

```cpp
// 中国剩余定理
// https://www.luogu.com.cn/problem/P1495
// https://www.bilibili.com/video/BV1AN4y1N7Su
// i64 都会爆啊，逆天
#include <bits/stdc++.h>
using i64 = __int128_t;
using namespace std;

istream &operator>>(istream &it, __int128_t &j)
{
    string val;
    it >> val;
    reverse(val.begin(), val.end());
    __int128_t ans = 0;
    bool f = 0;
    char c = val.back();
    val.pop_back();
    for (; c < '0' || c > '9'; c = val.back(), val.pop_back())
    {
        if (c == '-')
            f = 1;
        if (val.empty())
            break;
    }
    for (; c >= '0' && c <= '9'; c = val.back(), val.pop_back())
    {
        ans = ans * 10 + c - '0';
        if (val.empty())
            break;
    }
    j = f ? -ans : ans;
    return it;
}

ostream &operator<<(ostream &os, const __int128_t &j)
{
    string ans;
    function<void(__int128_t)> write = [&](__int128_t x)
    {
        if (x < 0)
            ans += '-', x = -x;
        if (x > 9)
            write(x / 10);
        ans += x % 10 + '0';
    };
    write(j);
    return os << ans;
}

array<i64, 3> exgcd(i64 a, i64 b)
{
    if (b == 0)
    {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 inv(i64 a, i64 b)
{
    auto [g, x, y] = exgcd(a, b);
    return x > 0 && x % b != 0 ? x % b : x % b + b;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n + 1), b(n + 1);
    i64 M = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i] >> a[i];
        M *= b[i];
    }
  
    vector<i64> c(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        c[i] = M / b[i];
        d[i] = inv(c[i], b[i]);
    }

    i64 x = 0;
    for (int i = 1; i <= n; i++)
    {
        x = (x + a[i] * c[i] * d[i]) % M;
    }

    cout << x << '\n';

    return 0;
}
```
