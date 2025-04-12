#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 将 A B C 全部降序排序，则将满足 i * j * k <= K 的所有三元组的值找出来
 * 因为 i * j * k > K 的肯定不满足题意。
 * 可以两个两个地考虑，A[i - 1] * B[j] 与 A[i] * B[j - 1] 分辨不出谁大，
 * 但是一定都比 A[i] * B[j] 大。加上 C 同理。
 * 
 * 值得注意的是，i * j * k 枚举的过程是 二重调和级数，时间复杂度 O(nlog²n)
 */

vector<i64> res;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<i64> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    sort(a.begin() + 1, a.end(), greater<>());
    sort(b.begin() + 1, b.end(), greater<>());
    sort(c.begin() + 1, c.end(), greater<>());

    for (int i = 1; i <= n && i <= k; i++)
        for (int j = 1; j <= n && i * j <= k; j++)
            for (int l = 1; l <= n && i * j * l <= k; l++)
                res.push_back(a[i] * b[j] + b[j] * c[l] + a[i] * c[l]);
    
    nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<>());
    cout << res[k - 1];    

    return 0;
}