#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> ss;
    vector<int> pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ss.insert(a[i]);
        pre[i] = ss.size();
    }
    ss.clear();
    for (int i = n; i >= 1; i--)
    {
        ss.insert(a[i]);
        suf[i] = ss.size();
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    cout << ans << '\n';

    return 0;
}