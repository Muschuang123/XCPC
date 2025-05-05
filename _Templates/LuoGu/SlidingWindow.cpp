// P1886 滑动窗口 /【模板】单调队列
// https://www.luogu.com.cn/problem/P1886
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    deque<int> dq;
    // 求最大值，单调递减的队列。
    for (int i = 1; i <= n; i++) {
        while (dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        // i - k + 1 ~ i 是窗口大小
        if (dq.front() < i - k + 1)
            dq.pop_front();
        if (i >= k)
            cout << a[dq.front()] << " \n"[i == n];
    }

    dq.clear();

    // 求最小值，单调递增的队列。
    for (int i = 1; i <= n; i++) {
        while (dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() < i - k + 1)
            dq.pop_front();
        if (i >= k)
            cout << a[dq.front()] << " \n"[i == n];
    }

    return 0;
}