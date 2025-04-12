#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

int dp[102][102][8003];
char a[102][102];
// 自动机，微型 trie
// tr[操作][状态] = 当前状态 通过这个操作的 下一个状态
int tr[128][8003];
// 状态：sum / mul / cur
// sum: 已经处理过的总和
// mul: 当前的数处理完需要乘这个数
// cur: 正在处理的数

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    if (!isdigit(a[1][1]) || !isdigit(a[n][m]))
    {
        cout << 0 << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < t * t * t; k++)
                dp[i][j][k] = 0;

    auto work = [&](int i, int j, int k)
    {
        return (i * t + j) * t + k;
    };
    
    dp[1][1][work(0, 1, (a[1][1] - '0') % t)] = 1;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < t; j++)
            for (int k = 0; k < t; k++)
            {
                for (char c = '0'; c <= '9'; c++)
                    tr[c][work(i, j, k)] = work(i, j, (k * 10 + c - '0') % t);
                tr['+'][work(i, j, k)] = work((i + j * k) % t, 1, 0);
                tr['-'][work(i, j, k)] = work((i + j * k) % t, t - 1, 0);
                tr['*'][work(i, j, k)] = work(i, j * k % t, 0);
            }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < t * t * t; k++)
            {
                // 如果不是两个连续的符号，就合法
                // 当前状态由上一状态转移而来，使用预处理的 tr[][]
                if (isdigit(a[i][j]) || isdigit(a[i - 1][j]))
                    dp[i][j][tr[a[i][j]][k]] = (dp[i][j][tr[a[i][j]][k]] + dp[i - 1][j][k]) % mod;
                if (isdigit(a[i][j]) || isdigit(a[i][j - 1]))
                    dp[i][j][tr[a[i][j]][k]] = (dp[i][j][tr[a[i][j]][k]] + dp[i][j - 1][k]) % mod;
            }
    
    int ans = 0;
    // 枚举最后一个点的所有状态
    // 计算的时候把所有数都计算成 sum 的形式
    for (int i = 0; i < t; i++)
        for (int j = 0; j < t; j++)
            for (int k = 0; k < t; k++)
                if ((i + j * k) % t == 0)
                    ans = (ans + dp[n][m][work(i, j, k)]) % mod;

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