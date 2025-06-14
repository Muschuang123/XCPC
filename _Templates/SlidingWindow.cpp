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