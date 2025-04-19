#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int maxn = 1e4 + 4;
int fa[maxn], tk[maxn], mm[maxn], vis[maxn], num[maxn];

int fin(int x) {
    return fa[x] == x ? x : fa[x] = fin(fa[x]);
}

void merg(int x, int y) {
    fa[fin(x)] = fin(y);
}

struct fam {
    int num, pp, t, m;
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < maxn; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        int id;
        cin >> id;
        vis[id] = 1;
        int fu, mu;
        cin >> fu >> mu;
        if (fu != -1) {
            merg(id, fu);
            vis[fu] = 1;
        }
        if (mu != -1) {
            merg(id, mu);
            vis[mu] = 1;
        }
        int k;
        cin >> k;
        while (k--) {
            int ch;
            cin >> ch;
            merg(id, ch);
            vis[ch] = 1;
        }
        cin >> tk[id] >> mm[id];
    }

    unordered_map<int, fam> mp;
    for (int i = 0; i <= 10000; i++) {
        if (vis[i]) {
            int root = fin(i);
            if (mp.find(root) == mp.end()) {
                mp[root] = {i, 0, 0, 0};
            } else {
                mp[root].num = min(mp[root].num, i);
            }
            mp[root].pp++;
            mp[root].t += tk[i];
            mp[root].m += mm[i];
        }
    }

    vector<fam> ans;
    for (auto &[f, s] : mp) {
        ans.push_back(s);
    }

    sort(ans.begin(), ans.end(), [](const fam &a, const fam &b) {
        if (a.m * b.pp > b.m * a.pp) {
            return true;
        } else if (a.m * b.pp == b.m * a.pp) {
            return a.num < b.num;
        } else {
            return false;
        }
    });

    cout << fixed << setprecision(3);
    cout << ans.size() << '\n';
    for (auto &[t1, t2, t3, t4] : ans) {
        cout << setw(4) << setfill('0') << t1 << ' ' << t2 << ' ' << 1.0 * t3 / t2 << ' ' << 1.0 * t4 / t2 << '\n';
    }

    return 0;
}