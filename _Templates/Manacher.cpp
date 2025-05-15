i64 manacher(string a, int n) {
    a[0] = '&';
    a.push_back('|');
    // d1 奇数回文半径（不含自身），d2 偶数回文半径
    vector<int> d1(n + 1), d2(n + 1);
    for (int i = 1, l = 1, r = 1; i <= n; i++) {
        if (i <= r) {
            d1[i] = min(d1[r - i + l], r - i);
        }
        while (a[i + d1[i] + 1] == a[i - d1[i] - 1]) {
            d1[i]++;
        }
        if (i + d1[i] > r) {
            r = i + d1[i];
            l = i - d1[i];
        }
    }
    for (int i = 2, l = 1, r = 2; i <= n; i++) {
        if (i <= r) {
            d2[i] = min(d2[r - i + l], r - i);
        }
        while (a[i + d2[i]] == a[i - d2[i] - 1]) {
            d2[i]++;
        }
        if (i + d2[i] > r) {
            r = i + d2[i];
            l = i - d2[i];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d1[i] * 2 + 1);
        ans = max(ans, d2[i] * 2);
    }
    return ans;
}