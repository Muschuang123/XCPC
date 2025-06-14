struct Manacher {
    // d1 奇数回文半径(不含自身),d2 偶数回文半径(abba d2[2] = 0,d2[3] = 2)
    vector<int> d1, d2;
    int n;

    // 1-indexed string
    void init(string s, int _n = 0) {
        n = _n ? _n : s.size() - 1;
        d1.assign(n + 1, 0), d2.assign(n + 1, 0);
        s[0] = '#', s.push_back('|');
        for (int i = 1, l = 1, r = 1; i <= n; i++) {
            if (i <= r) d1[i] = min(d1[r - i + l], r - i);
            while (s[i + d1[i] + 1] == s[i - d1[i] - 1]) d1[i]++;
            if (i + d1[i] > r) r = i + d1[i], l = i - d1[i];
        }
        for (int i = 2, l = 1, r = 2; i <= n; i++) {
            if (i <= r) d2[i] = min(d2[r - i + l], r - i);
            while (s[i + d2[i]] == s[i - d2[i] - 1]) d2[i]++;
            if (i + d2[i] > r) r = i + d2[i], l = i - d2[i];
        }
    }

    // 检查是否回文
    bool checkp(int l, int r) {
        if ((r - l + 1) & 1)
            return d1[(l + r) / 2] >= (r - l) / 2;
        return d2[l + (r - l + 1) / 2] >= (r - l + 1) / 2;
    }

    int getmax() {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max({ans, d1[i] * 2 + 1, d2[i] * 2});
        return ans;
    }
} ma;