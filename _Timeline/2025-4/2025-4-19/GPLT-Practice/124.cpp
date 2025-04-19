#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int n;
int a[32];
vector<int> g[32];

void dfs(int x, int fa) {
    if (x > n) {
        return;
    }
    dfs(x * 2, x);
    dfs(x * 2 + 1, x);
    cin >> a[x];
    g[fa].push_back(x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    dfs(1, 0);

    queue<int> q;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x != 1) {
            cout << ' ';
        }
        cout << a[x];
        for (auto &v : g[x]) {
            q.push(v);
        }
    }

    return 0;
}