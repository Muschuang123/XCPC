#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 5e5 + 5;

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
            if (!ch[u][v])
                ch[u][v] = ++idx;
            u = ch[u][v];
        }
        cnt[u]++;
    }

    // return the number of strings in Trie.
    int query(const string &s) {
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            int v = mp(s[i]);
            if (!ch[u][v])
                return 0;
            u = ch[u][v];
        }
        return cnt[u];
    }

    void clear() {
        for (int i = 0; i <= idx; i++) {
            cnt[i] = 0;
            for (int j = 0; j < Tsz; j++)
                ch[i][j] = 0;
        }
        idx = 0;
    }
} T;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        T.insert(s);
    }

    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        int res = T.query(s);
        if (res == 0) {
            cout << "WRONG\n";
        } else if (res == 1) {
            cout << "OK\n";
            T.insert(s);
        } else {
            cout << "REPEAT\n";
        }
    }

    return 0;
}