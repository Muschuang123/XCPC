// 拓扑排序优化的 AC自动机
// 默认 'a' ~ 'z'
// maxn = ∑|s| ，s 为模式串
// insert() ==> build() ==> work() ==> topo()
// res[idx[i]] 为 s[i] 的答案
// dp 时注意 string 是 0-index
const int Tsz = 26;
struct Trie {
    int ch[maxn][Tsz], ne[maxn], in[maxn];
    int res[maxn], tot;
    int mp(char c) { return c - 'a'; }
    // 返回一个 idx ，用于定位答案，相同的模式串 idx 相同
    int insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int &v = ch[u][mp(s[i])];
            if (!v) {
                v = ++tot;
            }
            u = v;
        }
        return u;
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
    // work 之后， res[idx] 就是对应模式串的出现次数
    void work(const string &s) {
        // 未拓扑优化：
        // int u = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     u = ch[u][mp(s[i])];
        //     int t = u;
        //     while (t) {
        //         res[t]++;
        //     }
        // }
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            u = ch[u][mp(s[i])];
            res[u]++;
        }
    }
    void topo() {
        queue<int> q;
        for (int i = 0; i <= tot; i++) {
            if (!in[i]) q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res[ne[u]] += res[u];
            if (!--in[ne[u]]) q.push(ne[u]);
        }
    }
    void clear() {
        for (int i = 0; i <= tot; i++) {
            res[i] = ne[i] = in[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        tot = 0;
    }
} AC;