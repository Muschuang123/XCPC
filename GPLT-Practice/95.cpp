#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[31];

void dfs(string &s, string &t) {
    int r = (int)s.size() - 1;
    int cur = s[r];
    if (r == 0) {
        return;
    }
    int p = -1;
    for (p = r; p >= 0 && t[p] != cur; p--);
    if (p > 0) {
        g[cur].push_back(s[p - 1]);
        string ls = s.substr(0, p);
        string lt = t.substr(0, p);
        dfs(ls, lt);
    }
    if (r - p > 0) {
        g[cur].push_back(s[r - 1]);
        string rs = s.substr(p, r - p);
        string rt = t.substr(p + 1, r - p);
        dfs(rs, rt);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t.push_back(x);
    }
    dfs(s, t);

    queue<int> q;
    q.push(s.back());
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x != s.back()) {
            cout << ' ';
        }
        cout << x;
        for (auto &v : g[x]) {
            q.push(v);
        }
    }

    return 0;
}