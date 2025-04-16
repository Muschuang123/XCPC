#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    reverse(a.begin() + 1, a.end());

    vector<int> dp(1);
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(dp.begin() + 1, dp.end(), a[i], greater<int>());
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << dp.size() - 1;

    return 0;
}