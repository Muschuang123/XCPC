#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxn = 1e5 + 5;

int parent[10000];
int findp(int x) {
    return parent[x] == x ? x : parent[x] = findp(parent[x]);
}
void unionp(int a, int b) {
    int ra = findp(a), rb = findp(b);
    if (ra != rb) {
        if (ra < rb) parent[rb] = ra;
        else parent[ra] = rb;
    }
}
struct Family {
    int minId;
    int members;
    int totalHouses;
    double totalArea;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < 10000; i++) {
        parent[i] = i;
    }
    vector<bool> exist(10000, false);
    vector<int> houses(10000, 0);
    vector<double> area(10000, 0.0);
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        exist[id] = true;
        int father, mother;
        cin >> father >> mother;
        if (father != -1) {
            unionp(id, father);
            exist[father] = true;
        }
        if (mother != -1) {
            unionp(id, mother);
            exist[mother] = true;
        }
        int k;
        cin >> k;
        while (k--) {
            int child;
            cin >> child;
            unionp(id, child);
            exist[child] = true;
        }
        cin >> houses[id] >> area[id];
    }
    unordered_map<int, Family> families;
    for (int i = 0; i < 10000; i++) {
        if (exist[i]) {
            int r = findp(i);
            if (families.find(r) == families.end()) {
                families[r] = {i, 0, 0, 0.0};
            } else {
                families[r].minId = min(families[r].minId, i);
            }
            families[r].members++;
            families[r].totalHouses += houses[i];
            families[r].totalArea += area[i];
        }
    }
    vector<Family> res;
    for (auto &p : families)
        res.push_back(p.second);
    sort(res.begin(), res.end(), [](const Family &a, const Family &b) {
        double avgA = a.totalArea / a.members;
        double avgB = b.totalArea / b.members;
        if (fabs(avgA - avgB) > 1e-9)
            return avgA > avgB;
        return a.minId < b.minId;
    });
    cout << res.size() << "\n";
    cout << fixed << setprecision(3);
    for (auto &f : res) {
        double avgHouses = (double)f.totalHouses / f.members;
        double avgArea = f.totalArea / f.members;
        cout << setw(4) << setfill('0') << f.minId << " "
            << f.members << " " << avgHouses << " " << avgArea << "\n";
    }
    return 0;
}