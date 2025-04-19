#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    getline(cin, s);
    int n = s.size();
    s = " " + s;
    int ans = 0;
    // odd
    for (int i = 1; i <= n; i++) {
        int res = 0;
        for (int j = 0; i + j <= n && i - j >= 1 && s[i + j] == s[i - j]; j++, res++);
        ans = max(res * 2 - 1, ans);
    }
    // even
    for (int i = 1; i + 1 <= n; i++) {
        int res = 0;
        for (int j = 0; i + j + 1 <= n && i - j >= 1 && s[i + j + 1] == s[i - j]; j++, res++);
        ans = max(res * 2, ans);
    }
    cout << ans << '\n';

    return 0;
}