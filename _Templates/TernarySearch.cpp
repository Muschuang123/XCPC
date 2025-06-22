// 寻找单峰，最大值
int l = 0, r = *max_element(a.begin() + 1, a.end()) + 1;
while (l + 1 < r) {
    int d = (r - l + 1) / 3;
    int ml = l + d;
    int mr = r - d;
    // 修改成 >= 就是最小值
    if (check(ml) <= check(mr)) {
        l = ml;
    } else {
        r = mr;
    }
}
cout << check(l) << '\n';