#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n, k;
i64 ans = 0;

void dfs(int i, int cur, int mi)
{
    if (i == k + 1 && cur == 0)
    {
        ans++;
        return;
    }
    if (cur == 0 || (k - i + 1) * mi < cur)
        return;
    for (int o = 1; o <= min(mi, cur); o++)
    {
        dfs(i + 1, cur - o, o);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> k;
    dfs(1, n, n);
    cout << ans << '\n';

    return 0;
}