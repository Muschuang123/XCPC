struct StringHash {
    int bas = 13331, n = 0;
    vector<unsigned long long> pre;
    StringHash(int _n, int _base = 13331, string &s) {
        bas = _base;
        pre.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] * bas + s[i];
        }
    }
};
