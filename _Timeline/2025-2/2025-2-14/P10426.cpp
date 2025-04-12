#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 可以通过分解质因数，来化简式子
// 化简结果是 GCD(Ha, Hb, Hc).

// 代码实现：
// 开一个值域大小的 cnt[]，记录这个数可以被多少个 a[i] 整除
// 找出最大的 i 使得 cnt[i] >= 3，记为 p
// 对 a[] 进行排序
// 从前往后找最先出现的 可以被 p 整除 的三个数

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<int> cnt(1e5 + 5);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= a[i]; j++)
        {
            if (a[i] % j == 0)
            {
                cnt[j]++;
                cnt[a[i] / j]++;
                if (j == a[i] / j)
                    cnt[j]--;
            }
        }
    }

    int p = 0;
    for (int i = 1e5; i >= 1; i--)
    {
        if (cnt[i] >= 3)
        {
            p = i;
            break;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % p == 0)
        {
            cout << a[i] << ' ';
            res++;
        }
        if (res == 3)
            break;
    }

    return 0;
}