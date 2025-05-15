#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> manacher(string &s) {
    string t = "@#";
    for (int i = 0; i < s.size(); i++) {
        t.push_back(s[i]);
        t.push_back('#');
    }
    t.push_back('$');
    int n = t.size() - 2;
    // 回文半径（不包括自身
    vector<int> d(n + 1);
    // 盒子 : [l, r] ，是一段回文串
    for (int i = 1, l = 1, r = 1; i <= n; i++) {
        if (i <= r) {
            // 盒子内与 i 对称的位置，最长不超出盒子
            d[i] = min(d[r - i + l], r - i);
        }
        // 如果能的话（通常是超出盒子了）继续暴力拓展
        while (t[i - d[i] - 1] == t[i + d[i] + 1]) {
            d[i]++;
        }
        // 回文涉及到的最右边比 r 还靠右，更新盒子
        if (i + d[i] > r) {
            l = i - d[i];
            r = i + d[i];
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    vector<int> d = manacher(s);
    cout << *max_element(d.begin() + 1, d.end());

    return 0;
}