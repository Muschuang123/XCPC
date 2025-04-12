#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int l, n;
vector<int> hh, lx;
int ans = 0;
int cur = 0;

void dfs(int x, int y)
{
    if (x == n + 1 && y == 1)
    {
        if (count(hh.begin() + 1, hh.end(), l) == n &&
            count(lx.begin() + 1, lx.end(), l) == n)
            ans++;
        return;
    }
    int nx, ny;
    if (y < n)
        nx = x, ny = y + 1;
    else 
        nx = x + 1, ny = 1;

    if (x < n && y < n)
    {
        for (int i = 0; i <= l - max(hh[x], lx[y]); i++)
        {
            hh[x] += i;
            lx[y] += i;
            dfs(nx, ny);
            hh[x] -= i;
            lx[y] -= i;
        }
    }
    else if (y == n)
    {
        if (hh[x] < lx[y])
            return;
        int i = l - hh[x];
        hh[x] += i;
        lx[y] += i;
        dfs(nx, ny);
        hh[x] -= i;
        lx[y] -= i;
    }
    else
    {
        if (lx[y] < hh[x])
            return;
        int i = l - lx[y];
        hh[x] += i;
        lx[y] += i;
        dfs(nx, ny);
        hh[x] -= i;
        lx[y] -= i;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> l >> n;
    hh.resize(n + 1);
    lx.resize(n + 1);
    dfs(1, 1);
    cout << ans << '\n';

    return 0;
}