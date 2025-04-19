#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
vector<int> dep;

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1;
    for (auto &v : g[x]) {
        dfs(v, x);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    dep.resize(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            q.push(i);
        } else {
            g[x].push_back(i);
        }
    }

    dfs(q.front(), 0);
    // while (q.size()) {
    //     dfs(q.front(), 0);
    //     q.pop();
    // }

    int mx = *max_element(dep.begin() + 1, dep.end());
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dep[i] == mx) {
            ans.push_back(i);
        }
    }

    cout << mx << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) {
            cout << ' ';
        }
        cout << ans[i];
    }

    return 0;
}