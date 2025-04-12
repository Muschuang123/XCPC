#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c1 = count(s.begin(), s.end(), '1');
    set<int> ss;
    // B == popcount(B) + c1
    for (int i = 0; i <= k; i++) {
        int t = c1 + i;
        t %= 1 << k;
        if (__builtin_popcount(t) == i) {
            ss.insert(t);
        }
    }
    if (ss.empty()) {
        cout << "None\n";
    } else {
        // 十进制转二进制
        int t = *ss.begin();
        string ans;
        for (int i = 0; i < k; i++) {
            if (t & 1) {
                ans.push_back('1');
            } else {
                ans.push_back('0');
            }
            t >>= 1;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
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