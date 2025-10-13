// 凹函数寻找最小值
// 寻找范围 [l, r)
int l = DOM_MIN, r = DOM_MAX + 1;
while (r - l > 3) { // 缩小到一个很小的区间
    int d = (r - l) / 3;
    int ml = l + d;
    int mr = r - d;
    // 修改成 <= 就是最大值
    if (check(ml) >= check(mr)) {
        l = ml;
    } else {
        r = mr;
    }
}
// 逐个检查
int mi = RAN_MAX;
for (int i = l; i < r; i++) {
    mi = min(mi, check(i));
}