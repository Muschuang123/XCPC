#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// return : 0-index | params : 1-index
vector<i64> xorbasis(vector<i64> a) {
    int n = (int)a.size() - 1;
    int cur = 1;
    for (int i = 62; i >= 0; i--) {
        // 找到第一个第 i 位为 1 的行
        for (int j = cur; j <= n; j++) {
            if (a[j] >> i & 1) {
                swap(a[cur], a[j]);
                break;
            }
        }
         // 如果 cur 行第 i 位还是 0，跳过
        if (a[cur] >> i & 1 ^ 1) {
            continue;
        }
        // 消去其他行的第 i 位
        for (int j = 1; j <= n; j++) {
            if (j != cur && (a[j] >> i & 1)) {
                a[j] ^= a[cur];
            }
        }
        cur++;
        if (cur == n + 1) {
            break;
        }
    }
    // 收集并返回线性基
    vector<i64> ans;
    for (int i = 1; i < cur; i++) {
        ans.push_back(a[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<i64> res = xorbasis(a);
    i64 ans = 0;
    for (auto &e : res) {
        ans ^= e;
    }
    cout << ans << '\n';

    return 0;
}