#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 k, z, ji = 0;
    cin >> k >> z;
    vector<i64> b(k);
    vector<int> vis(k);
    vector<int> c1;
    for (int i = 0; i < k; i++) {
        cin >> b[i];
        ji += b[i] % 2;
        if (b[i] == 1) {
            c1.push_back(i);
        }
    }

    string ans(k, '#');
    if ((z + ji) % 2) {
        // fl == 0 : Alice      
        // fl == 1 : Bob
        int fl = 0;
        while (c1.size()) {
            if (!fl) {
                fl = 1;
                ans[c1.back()] = '1';
                b[c1.back()]--;
            } else {
                fl = 0;
                ans[c1.back()] = '0';
                b[c1.back()]--;
            }
            c1.pop_back();
        }
        for (int i = 0; i < k; i++) {
            if (ans[i] == '#') {
                if (b[i]) {
                    ans[i] = '1';
                } else {
                    ans[i] = '0';
                }
            }
        }
    } else {
        // fl == 0 : Alice      
        // fl == 1 : Bob
        int fl = 0;
        while (c1.size()) {
            if (!fl) {
                fl = 1;
                ans[c1.back()] = '1';
                b[c1.back()]--;
            } else {
                fl = 0;
                ans[c1.back()] = '0';
                b[c1.back()]--;
            }
            c1.pop_back();
        }
        for (int i = 0; i < k; i++) {
            if (ans[i] == '#') {
                ans[i] = '0';
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}