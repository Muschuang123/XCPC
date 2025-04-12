struct PersistentSeg
{
    struct tree
    {
        int lc, rc, ans;
    } tr[20 * maxn]; // 要开20倍空间
    int root[maxn], cur;
    int a[maxn], n, b[maxn], p;

    void add(int &now, int last, int l, int r, int x)
    {
        now = ++cur;
        tr[now].ans = tr[last].ans + 1;
        tr[now].lc = tr[last].lc;
        tr[now].rc = tr[last].rc;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (x <= mid)
            add(tr[now].lc, tr[last].lc, l, mid, x);
        else
            add(tr[now].rc, tr[last].rc, mid + 1, r, x);
    }

    int query(int L, int R, int l, int r, int x) // 求中位数:query(root[l - 1], root[r], 1, p, (r - l) / 2 + 1)
    {
        if (l == r)
            return l;
        int sum = tr[tr[R].lc].ans - tr[tr[L].lc].ans;
        int mid = l + r >> 1;
        if (x <= sum)
            return query(tr[L].lc, tr[R].lc, l, mid, x);
        else
            return query(tr[L].rc, tr[R].rc, mid + 1, r, x - sum);
    }

    int get(int x)
    {
        return lower_bound(b + 1, b + 1 + p, x) - b;
    }

    void init(int _n)
    {
        n = _n, cur = 0;
        for (int i = 0; i <= n; i++)
        {
            tr[i] = {0, 0, 0};
            root[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            b[i] = a[i];
        sort(b + 1, b + 1 + n);
        p = unique(b + 1, b + 1 + n) - b - 1;
        for (int i = 1; i <= n; i++)
        {
            int pos = get(a[i]);
            add(root[i], root[i - 1], 1, p, pos);
        }
    }
} t;