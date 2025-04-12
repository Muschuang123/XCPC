// 树剖
int dep[N], sz[N], son[N], top[N], fa[N];

void dfs1(int x, int father)
{
    sz[x] = 1;
    dep[x] = dep[father] + 1;
    fa[x] = father;
    for (int i = head[x]; i; i = e[i].ne)
    {
        int y = e[i].to;
        if (y == father)
            continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (!son[x] || sz[son[x]] < sz[y])
            son[x] = y;
    }
}

void dfs2(int x, int tv)
{
    top[x] = tv;
    if (!son[x])
        return;
    dfs2(son[x], tv);
    for (int i = head[x]; i; i = e[i].ne)
    {
        int y = e[i].to;
        if (y == son[x] || y == fa[x])
            continue;
        dfs2(y, y);
    }
}

int lca(int x, int y)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}