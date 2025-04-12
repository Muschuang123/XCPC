// https://www.luogu.com.cn/article/bj8tcza8
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 4e5 + 5;

vector<int> pri;
bool not_prime[maxn];
int minp[maxn];
void euler(int n)
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

void solve()
{
    // 质数只能由自己 generate
    // 合数都能由 2 generate
    // 偶合数显然，都能被 2 整除
    // 奇合数可以减去一个 任意一个因子，变成偶合数。
    // 2 是最小的质数，这让一切变得好办
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (!not_prime[a[i]])
        {
            p.insert(a[i]);
        }
    }

    if (p.size() >= 2)
    {
        // 如果质数的个数大于 2，说明选不出一个比所有 a[i] 都小的 generator
        // 你选其中一个质数，另一个质数就生成不了
        // 你选两个质数的LCM，就必定大于两个质数
        cout << -1 << '\n';
    }
    else if (p.size() == 0)
    {
        // 没有质数，说明都可以由 2 generate
        cout << 2 << '\n';
    }
    else
    {
        // 找到这个质数 x
        int x = *p.begin();
        // 注意，x 现在只能 + 自己
        for (int i = 1; i <= n; i++)
        {
            // x 自己能生成自己。
            if (a[i] == x)
                continue;
            
            // 考虑 x 生成别人的情况
            if (a[i] % 2 == 0)
            {
                // 如果是偶合数，那么需要 2 * x <= a[i] 做出 2
                if (2 * x > a[i])
                {
                    cout << -1 << '\n';
                    return;
                }
            }
            else
            {
                // 如果是奇合数，那么需要 2 * x <= a[i] - minp[a[i]]
                // 显然 a[i] - minp[a[i]] 是 奇数 - 奇数 是偶数，回到偶合数情况
                // 所以 2 * x 可以生成 a[i] - minp[a[i]]
                // a[i] - minp[a[i]] 还有 minp[a[i]] 这个因子，所以可以 generate a[i]

                // 如果 存在一个 y 可以一步生成 a[i]，说明存在 一个 y 的因子 d
                // 使得 y + d = a[i]，需要 d 必定是 y 的因子，那么这必定是 a[i] 的因子
                // 故 d >= minp[a[i]]，y <= a[i] - minp[a[i]]
                // 所以对于任意 可以 生成 a[i] 的数 z
                // z <= y <= a[i] - minp[a[i]]
                // 回到题目，当前 x 在 变成 2 * x 之前，只能生成 2 * x
                // 只有变成 2 * x ，才能生成其他数
                if (2 * x > a[i] - minp[a[i]])
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        cout << x << '\n';
    }
    
}

int main()
{
    euler(4e5);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}