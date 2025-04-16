#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int k;
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        unordered_set<int> ss;
        while (x--) {
            int t;
            cin >> t;
            ss.insert(t);
        }
        int ok = 1;
        for (int i = 1; i <= m; i++) {
            if (!ss.count(a[i].first) && !ss.count(a[i].second)) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}