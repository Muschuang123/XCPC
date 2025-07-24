vector<Point<i64>> tubao(vector<Point<i64>> a, int n) {
    // 按照 x 坐标排序
    sort(a.begin() + 1, a.end());

    vector<Point<i64>> top, bot;
    for (int i = 1; i <= n; i++) {
        auto [x, y] = a[i];
        while (top.size() > 1) {
            auto [x1, y1] = top[top.size() - 1];
            auto [x2, y2] = top[top.size() - 2];
            if ((y - y1) * (x1 - x2) >= (y1 - y2) * (x - x1)) {
                top.pop_back();
            } else {
                break;
            }
        }
        top.push_back(a[i]);
        while (bot.size() > 1) {
            auto [x1, y1] = bot[bot.size() - 1];
            auto [x2, y2] = bot[bot.size() - 2];
            if ((y - y1) * (x1 - x2) <= (y1 - y2) * (x - x1)) {
                bot.pop_back();
            } else {
                break;
            }
        }
        bot.push_back(a[i]);
    }
    // 逆时针凸包
    auto tb = bot;
    // i >= 0 则第一个点和最后一个点相同
    // i >= 1 则省略最后一个点
    for (int i = top.size() - 2; i >= 0; i--) {
        tb.push_back(top[i]);
    }
    return tb;
}


// 求凸包直径
i64 diameter(vector<Point<i64>> &tb) {
    int n = tb.size();
    // 凸包上只有两个点
    if (n == 3) {
        cout << disEx(tb[0], tb[1]) << '\n';
        return 0;
    }
    i64 ans = 0;
    for (int l = 1, r = 1; l < n; l++) {
        while (cross(tb[l - 1], tb[l], tb[r]) <= cross(tb[l - 1], tb[l], tb[(r + 1) % n])) {
            r = (r + 1) % n;
        }
        ans = max({ans, disEx(tb[l], tb[r]), disEx(tb[l - 1], tb[r])});
    }
    return ans;
}