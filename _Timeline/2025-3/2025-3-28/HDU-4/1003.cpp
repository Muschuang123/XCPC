#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 这个方法泛用性比较强，可以求 位运算的不等式
// 挨个判断每一个位，如果是 0 是否可以断言 不等式成立
// 反之则判断下一位

void solve()
{
    i64 k, b, c, v;
    cin >> k >> b >> c >> v;

    // 用 p 的取值范围 [l, r] 检验 有多少种 x 的取值
    auto work = [&](i64 l, i64 r) -> i64
    {
        if (r < b)
            return 0;
        return (r - b) / k - max(0LL, (l - 1 - b) / k) + (l <= b && b <= r);
    };

    // cur 用于模拟当前的 p
    i64 ans = 0, cur = 0;
    // (p ^ c) < v
    for (int i = 62; i >= 0; i--)
    {
        i64 x = v >> i & 1, y = c >> i & 1;
        // p ^ c 第 i 位是 0 ，可以断言 (p ^ c) < v，后面可以随意取值
        // 因为 v 这一位是 1
        // 在随意取值这段连续的区间内，看看有多少个 x 符合答案。使用work() 计算
        if (x)
        {
            // 为了让 第 i 位是 0
            // 如果 c 的第 i 位 (即 y) 是 0 ，那么让这一位也是 0
            ans += work(cur + (y << i), cur + (y << i) + (1LL << i) - 1);
        }
        // 让 p ^ c 这一位是 v 的这一位，继续判断后面的位
        cur += (x ^ y) << i;
    }
    // (p ^ c) == v
    ans += work(c ^ v, c ^ v);
    cout << ans << '\n';
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