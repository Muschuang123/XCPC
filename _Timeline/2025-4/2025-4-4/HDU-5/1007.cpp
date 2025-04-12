#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

set<int> fa[5003];

bool dfs(int x, int l, int ntf) {
    if (x == ntf)
        return 1;
    bool res = 0;
    for (auto &v : fa[x]) {
        if (x != l)
            res |= dfs(v, x, ntf);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    cin.ignore(80, '\n');

    map<string, int> mp;
    mp["main"] = 1;
    // 当前所在分支
    string head = "main";
    // 当前节点个数
    int num = 1;
    while (n--) {
        string TT;
        getline(cin, TT);
        stringstream ss;
        ss << TT;

        string s;
        ss >> s;
        if (s == "commit") {
            fa[++num].clear();
            fa[num].insert(mp[head]);
            mp[head] = num;
        } else if (s == "branch") {
            ss >> s;
            if (s != "-d") {
                string name = s;
                ss >> s;
                if (mp.count(name)) {
                    continue;
                }
                if (ss.fail()) {
                    mp[name] = mp[head];
                } else {
                    mp[name] = stoi(s);
                }
            } else {
                ss >> s;
                mp.erase(s);
            }
        } else if (s == "merge") {
            ss >> s;
            if (!dfs(mp[head], 0, mp[s]) && !dfs(mp[s], 0, mp[head])) {
                fa[++num].clear();
                fa[num].insert(mp[head]);
                fa[num].insert(mp[s]);
                mp[head] = num;
            } else if (dfs(mp[s], 0, mp[head])) {
                // head = s;
                mp[head] = mp[s];
            }
        } else if (s == "checkout") {
            ss >> s;
            head = s;
        } else if (s == "reset") {
            ss >> s;
            if (!ss.fail()) {
                mp[head] = stoi(s);
            }
        }
        cout << "";
    }
    cout << mp.size() << '\n';
    for (auto &[f, s] : mp) {
        cout << f << ' ' << s << '\n';
    }
    cout << num << '\n';
    for (int i = 1; i <= num; i++) {
        cout << fa[i].size();
        for (auto &v : fa[i]) {
            cout << ' ' << v;
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}