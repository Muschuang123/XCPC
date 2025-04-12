#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 把 i -> j 询问，作为有向边，我们可以构造一个图。
// 想要找到内鬼，必须让所有点都包含在环内。
// 否则，内鬼可以在入度为 0 的点，或者出度为 0 的点上分辨不出来。

// 如何通过环来排查内鬼呢？

// 我们可以发现，骑士 -> 骑士 or 骗子 -> 骗子 回答总是为真
// 而 骑士 -> 骗子 or 骗子 -> 骑士 回答总是为假。
// 如果没有内鬼，环内 必然有 偶数个 骑士 -> 骗子 or 骗子 -> 骑士。
// 即，偶数个假。
// 通过枚举将 内鬼 加在 骑上 或 骗子 之间的 4 种情况，发现这会导致奇数个 0 出现。
// 所以当且仅当有内鬼，环上有奇数个 0。

// 做成环之后，我们要让所有的环尽可能小，可以缩小搜查范围。
// n 为偶数，我们通过 n - 2 次询问，可以确定内鬼在哪个二元环，
// 然后用最后两次找出谁是内鬼。
// n 为奇数，我们必须 做出一个 三元环的询问，
// 按照之前的推理，如果有内鬼，我们可以再通过两次询问查出内鬼。
// 具体地，加上之前的询问，再两条反向边，就能得到答案。

// 特别的，n == 3 需要 4 次。

void q(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
}

void ans(int a)
{
    cout << "! " << a << endl;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        int a, b, c, d;
        q(1, 2);
        cin >> a;
        q(2, 1);
        cin >> b;
        if (a == b)
        {
            ans(3);
            return;
        }
        q(2, 3);
        cin >> c;
        q(3, 2);
        cin >> d;
        if (c == d)
        {
            ans(1);
        }
        else
        {
            ans(2);
        }
    }
    else if (n % 2 == 0)
    {
        int a, b;
        for (int i = 1; i <= n - 2; i += 2)
        {
            q(i, i + 1);
            cin >> a;
            q(i + 1, i);
            cin >> b;
            if (a != b)
            {
                int j = 1;
                for (; j == i || j == i + 1; j++);
                int c, d;
                q(i, j);
                cin >> c;
                q(j, i);
                cin >> d;
                if (c == d)
                {
                    ans(i + 1);
                }
                else
                {
                    ans(i);
                }
                return;
            }
        }
        q(1, n);
        cin >> a;
        q(n, 1);
        cin >> b;
        if (a == b)
        {
            ans(n - 1);
        } 
        else
        {
            ans(n);
        }
    }
    else
    {
        int z, x, v;
        q(1, 2);
        cin >> z;
        q(2, 3);
        cin >> x;
        q(3, 1);
        cin >> v;
        if ((z + x + v) % 2 == 0)
        {
            int k, l;
            q(2, 1);
            cin >> k;
            q(3, 2);
            cin >> l;
            if (k == z)
            {
                ans(3);
            }
            else if (l == x)
            {
                ans(1);
            }
            else
            {
                ans(2);
            }
        }
        else
        {
            int a, b;
            for (int i = 4; i <= n - 2; i += 2)
            {
                q(i, i + 1);
                cin >> a;
                q(i + 1, i);
                cin >> b;
                if (a != b)
                {
                    int j = 1;
                    for (; j == i || j == i + 1; j++);
                    int c, d;
                    q(i, j);
                    cin >> c;
                    q(j, i);
                    cin >> d;
                    if (c == d)
                    {
                        ans(i + 1);
                    }
                    else
                    {
                        ans(i);
                    }
                    return;
                }
            }
            q(1, n);
            cin >> a;
            q(n, 1);
            cin >> b;
            if (a == b)
            {
                ans(n - 1);
            } 
            else
            {
                ans(n);
            }
        }
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