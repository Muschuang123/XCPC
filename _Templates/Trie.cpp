// 默认 'a' ~ 'z'
// maxn = ∑|s| ，s 为模式串
const int Tsz = 26;
struct Trie {
    int ch[maxn][Tsz], cnt[maxn], tot;
    int mp(char c) { return c - 'a'; }
    void insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int &v = ch[u][mp(s[i])];
            if (!v) v = ++tot;
            u = v;
        }
        cnt[u]++;
    }
    int query(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = ch[u][mp(s[i])];
            if (!v) return 0;
            u = v;
        }
        return cnt[u];
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
} D;