// 要求区间内的值相同
// 1-index
for (int l = 1, r = 1; l < n; l = r) {
    while (r < n && s[l] == s[r]) {
        r++;
    }
    if (s[i] == x) {
        // ...
    }
}