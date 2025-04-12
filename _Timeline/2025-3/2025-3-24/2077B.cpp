#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve()
{
    // 能把 是 1 的位 掩盖掉。
    // 每个 10 看做一个单位，左右，
    // 如果最终 回答左 是 1 说明 实际右 是双 1
    // 如果最终 回答左 是 0 说明 实际右 是单 1
    // 奇偶交错，询问出每一位是双 1 还是单 1
    int x = 0b10'1010'1010'1010'1010'1010'1010'1010;
    int y = x >> 1;
    int a, b;
    cout << x << endl;
    cin >> a;
    // 为什么要减去两倍，因为假设 目标 俩数都是 0，回答就应该是 x << 1
    // 如果有的位不是 0，答案肯定还会加，
    // 我们处理的就是 减去 x << 1 之后的答案
    a -= x << 1;
    cout << y << endl;
    cin >> b;
    // 同上
    b -= y << 1;
    int t = 0, s = 0;
    for (int i = 0; i < 30; i++)
    {
        int cur = i % 2 ? b : a;
        // 00 -> 双 0
        // 01 -> 单 1
        // 10 -> 双 1
        if (cur >> i & 1)
        {
            t |= 1 << i;
        }
        else if (cur >> i + 1 & 1)
        {
            t |= 1 << i;
            s |= 1 << i;
        }
    }
    cout << "!" << endl;
    int q;
    cin >> q;
    cout << (q | t) + (q | s) << endl;
}

int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}