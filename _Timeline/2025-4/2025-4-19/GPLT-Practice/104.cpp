#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<double> a;
    for (int i = 1; i <= n; i++) {
        vector<double> t(m + 1);
        for (int j = 1; j <= m; j++) {
            cin >> t[j];
        }
        sort(t.begin() + 1, t.end());
        double sum = accumulate(t.begin() + 2, t.end() - 1, 0.0);
        a.push_back(sum / (m - 2));
    }
    sort(a.begin(), a.end());
    cout << fixed << setprecision(3);
    for (int i = n - k; i < a.size(); i++) {
        if (i > n - k) {
            cout << ' ';
        }
        cout << a[i];
    }

    return 0;
}