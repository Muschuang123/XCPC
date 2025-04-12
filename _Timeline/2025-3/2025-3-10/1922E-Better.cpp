#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/**
 * 一个递增的长序列贡献为 2^n - 1
 * 直接做是 log²X （最差），所以必须考虑优化。
 * 
 * log²X 证明: log 个序列，每个序列 log 长度
 * 
 * 先放上最长的上升序列，
 * 然后反复使用这段序列的一段。
 * 
 * 具体怎么用呢？
 * 假设有 1 2 3 4 5 这个最长序列，
 * 在序列前面放入 2，贡献来自 3 4 5 这一段，每一个数可以取或者不取，
 * 所以贡献是 2^3。同理，放入 1 是 2^4 .....
 * 
 * 结合这个最长序列贡献是 2^n - 1 与 空序列也算递增序列，
 * 我们可以对 X 拆位，然后先放 最高位长度的 序列，然后在序列前面添数。
 * 
 * 第一次写得有点丑了，因为刚开始是直接做的，没有算到最差是 log²X。
 */

void solve()
{
    i64 x;
    cin >> x;
    vector<int> res;
    int dig = 0;
    while (x)
    {
        if (x & 1)
            res.push_back(dig);
        dig++;
        x >>= 1;
    }

    vector<int> ans;
    for (int i = 0; i < res.back(); i++)
        ans.push_back(i);
    int mx = res.back();
    res.pop_back();

    reverse(ans.begin(), ans.end());
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        ans.push_back(mx - res[i] - 1);
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int &e : ans)
        cout << e << ' ';
    cout << '\n';
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