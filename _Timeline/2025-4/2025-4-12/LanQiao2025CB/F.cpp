#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string a, b;
    cin >> a >> b;
    int n = a.size();
    a = "#" + a;
    b = "#" + b;
    for (int i = n; i >= 0; i--) {
        if (a[i] == '#' || b[i] == '#') {
            n = i;
            break;
        }
    }

    int l = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '#' || b[i] == '#') {
            l = i;
            break;
        }
    }
    if (l == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0x3f3f3f3f));
    dp[l - 1][0] = dp[l - 1][1] = 0;
    for (int i = l; i <= n; i++) {
        if (a[i] == '#') {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (b[i] == '#') {
            dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        }
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        
        if (a[i] == '#') {
            dp[i][0] = min(dp[i][0], dp[i][1]);
        }
        if (b[i] == '#') {
            dp[i][1] = min(dp[i][1], dp[i][0]);
        }

        dp[i][0] = min(dp[i][0], dp[i][1] + 1);
        dp[i][1] = min(dp[i][1], dp[i][0] + 1);
    }
    cout << min(dp[n][0], dp[n][1]);

    return 0;
}