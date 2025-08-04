#include <bits/stdc++.h>
using ld = long double;
using i64 = long long;
using namespace std;

const int maxn = 1e6 + 6;

// 拓扑排序优化的 AC自动机
// 默认 'a' ~ 'z'
// maxn = ∑|s| ，s 为模式串
// insert() ==> build() ==> work()
// ans[idx[i]] 为 s[i] 的答案
const int Tsz = 26;
struct Trie {
    int ch[maxn][Tsz], cnt[maxn], ne[maxn], in[maxn];
    int res[maxn], rnk[maxn], ans[maxn];
    int tot, knt;
    int mp(char c) { return c - 'a'; }
    // 返回一个 rnk，用于定位答案，相同的模式串 rnk 相同
    int insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int &v = ch[u][mp(s[i])];
            if (!v) v = ++tot;
            u = v;
        }
        cnt[u]++;
        if (!rnk[u]) rnk[u] = ++knt;
        return rnk[u];
    }
    void build() {
        queue<int> q;
        for (int i = 0; i < Tsz; i++) {
            if (ch[0][i]) q.push(ch[0][i]);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < Tsz; i++) {
                int &v = ch[u][i];
                if (v) { // 有孩子，同步 ne[v] 为 ne[u] 的儿子
                    ne[v] = ch[ne[u]][i];
                    in[ne[v]]++;
                    q.push(v);
                } else { // 否则下一步就是 ne[u] 的儿子
                    v = ch[ne[u]][i];
                }
            }
        }
    }
    // work 之后，ans[idx] 就是对应模式串的出现次数
    void work(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            u = ch[u][mp(s[i])];
            res[u]++;
        }
        queue<int> q;
        for (int i = 0; i <= tot; i++) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (rnk[u]) ans[rnk[u]] = res[u];
            res[ne[u]] += res[u];
            if (!--in[ne[u]]) q.push(ne[u]);
        }
    }
    void clear() {
        for (int i = 0; i <= tot; i++) {
            cnt[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        tot = 0;
    }
} AC;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> idx(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        idx[i] = AC.insert(s);
    }
    AC.build();
    string s;
    cin >> s;
    AC.work(s);
    for (int i = 1; i <= n; i++) {
        cout << AC.ans[idx[i]] << '\n';
    }

    return 0;
}