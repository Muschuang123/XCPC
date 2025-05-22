// https://codeforces.com/gym/105851/problem/H
// 高斯消元 行数列数不同的矩阵
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 2e3 + 3;
using BS = bitset<maxn>;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    vector<BS> a(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m + 1; j <= m + p; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }

    int cur = 1;
    vector<int> ma(n + 1);
    // 寻找主元列，i > m 说明找完了所有列，cur > n 说明找够了。
    for (int i = 1; i <= m && cur <= n; i++) {
        int fz = cur;
        for (int k = cur + 1; k <= n; k++) {
            if (a[k][i]) {
                fz = k;
                break;
            }
        }
        if (!a[fz][i]) {
            continue;
        }
        // 第 cur 个主元，在第 i 列
        ma[cur] = i;
        // 提到 cur 这一行
        swap(a[cur], a[fz]);
        for (int k = 1; k <= n; k++) {
            // 需要消
            if (cur != k && a[k][i]) {
                a[k] ^= a[cur];
            }
        }
        cur++;
    }

    while (cur <= n) {
        for (int j = m + 1; j <= m + p; j++) {
            if (a[cur][j]) {
                cout << "No\n";
                return 0;
            }
        }
        cur++;
    }
    
    cout << "Yes\n";
    vector<BS> b(m + 1);
    for (int i = 1; i <= n; i++) {
        int w = ma[i];
        for (int j = m + 1; j <= m + p; j++) {
            b[w][j - m] = a[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= p; j++) {
            cout << b[i][j] << " \n"[j == p];
        }
    }

    return 0;
}