// 'a' ~ 'z'
struct Trie {
    static const int Tsz = 26;
    int ch[maxn][Tsz], cnt[maxn];
    int idx = 0;

    Trie() {
        memset(ch, 0, sizeof(ch)), memset(cnt, 0, sizeof(cnt));
    }

    inline int mp(char c) {
        return c - 'a';
    }

    void insert(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp(s[i]);
            if (!ch[u][v]) {
                ch[u][v] = ++idx;
            }
            u = ch[u][v];
        }
        cnt[u]++;
    }

    int query(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp(s[i]);
            if (!ch[u][v]) {
                return 0;
            }
            u = ch[u][v];
        }
        return cnt[u];
    }

    void clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j < Tsz; j++) {
                ch[i][j] = 0;
            }
        }
        idx = 0;
    }
} D;