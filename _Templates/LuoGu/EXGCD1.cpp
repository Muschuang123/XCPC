// 扩展欧几里得算法 求二元一次不定方程的根
// https://www.luogu.com.cn/problem/P5656
// https://www.bilibili.com/video/BV1rD4y1C7qg
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

array<i64, 3> exgcd(i64 a, i64 b)
{
    if (b == 0)
    {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

void solve()
{
    i64 a, b, c;
    cin >> a >> b >> c;
    auto [g, x, y] = exgcd(a, b);
    if (c % g != 0)
    {
        cout << -1 << '\n';
        return;
    }

    a /= g, b /= g, c /= g;
    x *= c, y *= c;

    // 这里min是只最小正整数解，所以max求出来有可能是负的，说明没有正整数解。
    // x 和 y 是此消彼长的关系。
    i64 minx = x > 0 && x % b != 0 ? x % b : x % b + b;
    i64 maxy = (c - a * minx) / b;
    i64 miny = y > 0 && y % a != 0 ? y % a : y % a + a;
    i64 maxx = (c - b * miny) / a;

    if (maxy <= 0 || maxx <= 0)
    {
        cout << minx << ' ' << miny << '\n';
    }
    else
    {
        i64 cnt = (maxx - minx) / b + 1;
        cout << cnt << ' ' << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << ' ' << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}