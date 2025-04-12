int pa[maxn][22];
int dep[maxn];

void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    pa[x][0] = fa;
    for (int i = 1; i < 22; i++)
        pa[x][i] = pa[pa[x][i - 1]][i - 1];
    for (int i = head[x]; i; i = e[i].ne)
    {
        int y = e[i].to;
        if (y == fa)
            continue;
        dfs(y, x);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    for (int i = 21; i >= 0; i--)
    {
        if (dep[pa[x][i]] >= dep[y])
            x = pa[x][i];
    }
    if (x == y)
        return x;
    for (int i = 21; i >= 0; i--)
    {
        if (pa[x][i] != pa[y][i])
            x = pa[x][i], y = pa[y][i];
    }
    return pa[x][0];
}
