#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 这个方法实现起来细节少一点，不容易出错

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    
    i64 ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        i64 x = a.end() - lower_bound(a.begin() + 1, a.end(), i);
        i64 y = a.end() - lower_bound(a.begin() + 1, a.end(), n - i);
        ans += x * y - min(x, y);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}