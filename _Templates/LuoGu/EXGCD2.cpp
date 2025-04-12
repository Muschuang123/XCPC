// https://www.luogu.com.cn/problem/P1082
#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

array<i64, 3> exgcd(i64 a, i64 b)
{
    if (b == 0)
    {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}

i64 inv(i64 a, i64 b)
{
    auto [g, x, y] = exgcd(a, b);
    return x > 0 && x % b != 0 ? x % b : x % b + b;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    i64 a, b;
    cin >> a >> b;
    cout << inv(a, b) << '\n';

    return 0;
}