#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using namespace std;

// 128 乘法 快于 i64 除法

i64 p, x, k;
vector<i64> pk;
vector<pair<i64, int>> pp;
i64 ans = 0;

void dfs(int ki, int pi, i128 cur) {
    if (ki == pk.size() && pi == pp.size()) {
        ans++;
    } else if (ki == pk.size()) {
        auto [num, power] = pp[pi];
        for (int i = 0; i <= power && cur <= x; i++) {
            dfs(ki, pi + 1, cur);
            cur *= num;
        }
    } else {
        i64 num = pk[ki];
        while (cur <= x) {
            dfs(ki + 1, pi, cur);
            cur *= num;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    unordered_set<i64> ssk;
    cin >> p >> x >> k;
    for (int i = 2; k != 1 && i <= k / i; i++) {
        if (k % i == 0) {
            pk.push_back(i);
            ssk.insert(i);
            while (k % i == 0) {
                k /= i;
            }
        }
    }
    // > sqrt(k) 的只能有一个
    if (k > 1) {
        pk.push_back(k);
        ssk.insert(k);
    }

    for (int i = 2; p != 1 && i <= p / i; i++) {
        if (p % i == 0) {
            int res = 0;
            while (p % i == 0) {
                res++;
                p /= i;
            }
            if (!ssk.count(i)) {
                pp.emplace_back(i, res);
            }
        }
    }
    // > sqrt(p) 的只能有一个
    if (p > 1) {
        if (!ssk.count(p)) {
            pp.emplace_back(p, 1);
        }
    }

    dfs(0, 0, 1);
    cout << ans << '\n';

    return 0;
}