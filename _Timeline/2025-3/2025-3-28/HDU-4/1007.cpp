#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e4 + 5;

// g 正向图，h 反向图
vector<int> g[maxn], h[maxn];
// [先手左手][先手右手][后手左手][后手右手]
int id[10][10][10][10];
// array<int, 4> rid[maxn];
int ans[maxn];
// 能到达的必胜态的点数，== g[x].size() 时必败
int cnt[maxn];

// 添加一条 idx -> id[x][y][xx][yy] 的边
void add(int idx, int x, int y, int xx, int yy)
{
    if (x > y)
        swap(x, y);
    // 先手变后手，后手变先手
    int tar = id[xx][yy][x][y];
    g[idx].push_back(tar);
    h[tar].push_back(idx);
}

void init()
{
    queue<int> q;
    int idx = 0;
    for (int x = 0; x <= 9; x++)
        for (int y = 0; y <= 9; y++)
            for (int xx = 0; xx <= 9; xx++)
                for (int yy = 0; yy <= 9; yy++)
                {
                    id[x][y][xx][yy] = ++idx;
                    // rid[idx] = {x, y, xx, yy};
                    if (x == 0 && y == 0)
                    {
                        q.push(idx);
                        ans[idx] = 1;
                    }
                    else if (xx == 0 && yy == 0)
                    {
                        q.push(idx);
                        ans[idx] = 2;
                    }
                }
    // 剪枝，令每个人的 第一个手比第二个手小
    // 每个人右手至少是 1，要不然就结束游戏了
    for (int x = 0; x <= 9; x++)
        for (int y = max(1, x); y <= 9; y++)
            for (int xx = 0; xx <= 9; xx++)
                for (int yy = max(1, xx); yy <= 9; yy++)
                {
                    int idx = id[x][y][xx][yy];
                    // 如果左手还有
                    if (x)
                    {
                        // 左手碰对面左手
                        if (xx) add(idx, (x + xx) % 10, y, xx, yy);
                        // 左手碰对面右手
                        add(idx, (x + yy) % 10, y, xx, yy);
                    }
                    // 右手碰对面左手
                    if (xx) add(idx, x, (y + xx) % 10, xx, yy);
                    // 右手碰对面右手
                    add(idx, x, (y + yy) % 10, xx, yy);
                }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        // 如果一个点能到达必败态，那么这个点是必胜态
        if (ans[x] == 2)
        {
            for (auto &v : h[x])
            {
                if (ans[v])
                    continue;
                q.push(v);
                ans[v] = 1;
            }
        }
        // 一个点只能到达必胜态，那么这个点是必败态
        else if (ans[x] == 1)
        {
            for (auto &v : h[x])
            {
                if (ans[v])
                    continue;
                cnt[v]++;
                if (cnt[v] == (int)g[v].size())
                {
                    q.push(v);
                    ans[v] = 2;
                }
            }
        }
    }
}

void solve()
{
    int x, y, xx, yy;
    cin >> x >> y >> xx >> yy;
    if (x > y)
        swap(x , y);
    if (xx > yy)
        swap(xx, yy);
    cout << ans[id[x][y][xx][yy]] << '\n';
}

int main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}