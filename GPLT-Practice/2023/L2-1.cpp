#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> st, box;
    auto print = [&]() {
        int cnt = 0;
        for (auto &e : st) {
            if (cnt != 0) {
                cout << ' ';
            }
            cout << e;
            cnt++;
        }
        cout << '\n';
        st.clear();
    };
    auto work = [&]() {
        while (box.size()) {
            if (st.size() < k && (st.empty() || st.back() >= box.back())) {
                st.push_back(box.back());
                box.pop_back();
            } else {
                if (st.size() == k) {
                    print();
                } else {
                    break;
                }
            }
        }
    };
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        work();
        if (st.empty() || st.back() >= a[i]) {
            st.push_back(a[i]);
        } else {
            if (box.size() == m) {
                print();
                work();
                i--;
            } else {
                box.push_back(a[i]);
            }
        }
        if (st.size() == k) {
            print();
        }
    }

    while (box.size()) {
        work();
        if (st.size()) {
            print();
        }
    }
    if (st.size()) {
        print();
    }

    return 0;
}