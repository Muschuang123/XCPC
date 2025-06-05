#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    // 先快速求s2的next数组
    vector<int> next(s2.size() + 1);
    next[0] = -1;
    if (s2.size() > 1)
        next[1] = 0;

    int i = 2, cn = 0;
    while (i <= s2.size()) {
        if (s2[i - 1] == s2[cn]) {
            next[i++] = ++cn;
        }
        // cn可以往前跳
        else if (cn > 0) {
            cn = next[cn];
        } else {
            next[i++] = 0;
        }
    }

    vector<int> ok;
    int x = 0, y = 0;
    while (x < s1.size()) {
        if (s1[x] == s2[y]) {
            x++;
            y++;
        } else if (y == 0) {
            x++;
        } else {
            y = next[y];
        }

        if (y == s2.size()) {
            x -= y - 1;
            ok.push_back(x);
            y = 0;
        }
    }

    for (int tt = 0; tt < ok.size(); tt++)
        cout << ok[tt] << '\n';
    for (int tt = 1; tt < next.size(); tt++)
        cout << next[tt] << ' ';

    return 0;
}