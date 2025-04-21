#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> sq, tq;
    char la = s.front();
    int cur = 1;
    for (u64 i = 1; i < s.size(); i++) {
        if (s[i] != la) {
            la = s[i];
            sq.push_back(cur);
            cur = 1;
        } else {
            cur++;
        }
    }
    sq.push_back(cur);

    la = t.front();
    cur = 1;
    for (u64 i = 1; i < t.size(); i++) {
        if (t[i] != la) {
            la = t[i];
            tq.push_back(cur);
            cur = 1;
        } else {
            cur++;
        }
    }
    tq.push_back(cur);

    if (s.front() != t.front() || sq.size() != tq.size()) {
        cout << "NO\n";
        return;
    }

    for (u64 i = 0; i < sq.size(); i++) {
        if (sq[i] > tq[i] || sq[i] * 2 < tq[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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