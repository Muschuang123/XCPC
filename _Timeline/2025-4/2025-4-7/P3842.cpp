#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n + 1);
    a[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    a[n].second = n;

    vector<i64> dp(n + 2, 1e18);
    dp[1] = -1;
    for (int i = 1; i <= n; i++) {
        vector<i64> tp = dp;
        dp.assign(n + 2, 1e18);
        auto [l, r] = a[i];
        auto [pl, pr] = a[i - 1];
        dp[l] = min(tp[pr] + abs(r - pr), tp[pl] + abs(r - pl)) + r - l + 1;
        dp[r] = min(tp[pl] + abs(l - pl), tp[pr] + abs(l - pr)) + r - l + 1;
    }
    cout << dp[n] << '\n';

    return 0;
}