#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    这个题时间给的很宽松。所以暴力。
    必须 a[i] > x 才能交换。而且序列要求 sorted 。
    所以 如果发生 a[i] > x ，那么必须交换，否则后面就换不了了。

    最小化交换次数，所以我们需要先检查一下是不是有序的，有序的就不用换了。
    如果有个点 i 打破了有序，那么 x 需要一直把前面满足 a[i] > x 的全换掉，一直换到 i。

    这样一直循环，直到有序就可以退出了。

    *: 判断无序可以用 a[i] > a[i + 1]。无需多写。
*/

int n, x;
vector<int> a;

bool check(int i)
{
    if (i == 0 || i == n)
        return 1;
    if (a[i] > a[i + 1])
        return 0;
    return 1;
}

void solve()
{
    cin >> n >> x;
    a.clear();
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    while (1)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            if (!check(i))
            {
                if (x >= a[i])
                {
                    cout << -1 << '\n';
                    return;
                }
                for (int j = 1; j <= i; j++)
                {
                    if (x < a[j])
                    {
                        swap(x, a[j]);
                        ans++;
                    }
                }
            }
        }

        vector<int> so = a;
        sort(so.begin() + 1, so.end());
        if (so == a)
            break;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}