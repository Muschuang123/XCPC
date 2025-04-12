#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    s = " " + s;
    vector<i64> r, b;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'R') {
            r.push_back(a[i]);
        } else {
            b.push_back(a[i]);
        }
    }
    sort(r.begin(), r.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    if (r.size() <= b.size()) {
        int sz = r.size();
        cout << accumulate(r.begin(), r.begin() + sz, 0LL) + 
            accumulate(b.begin(), b.begin() + sz, 0LL);
    } else {
        int sz = b.size(); 
        cout << accumulate(r.begin(), r.begin() + sz + 1, 0LL) + 
            accumulate(b.begin(), b.begin() + sz, 0LL);
    }
    cout << '\n';

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