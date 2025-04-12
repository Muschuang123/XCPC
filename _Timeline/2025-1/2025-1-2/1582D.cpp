#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    离线答案。保持sum是0直到n。根据a[n]和sum的gcd（尽可能的缩小b[i]），
        据此调节b[1]~b[n-1]并设置b[n]。
    排序保证了相邻两项不会差太多。不会造成sum在最终过大。
        逆序，后面的小数可以调节前面的大数造成的sum不稳定。
        如果都是大数，e.g. [1e4, 1e4, 1e4, ....., 1e4, 9999]
            也可以保证总大小 < 1e4 * 1e5 == 1e9.
    input:
        1
        4
        10000 10000 10000 9999

    output:
        9999 -9999 9999 -10000

*/

struct node
{
    int a, b, i, op;
};

bool operator < (const node &a, const node &b)
{
    return a.a > b.a;
}

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].i = i;
        if (a[i].a >= 0)
        {
            a[i].op = 1;
        }
        else
        {
            a[i].a = -a[i].a;
            a[i].op = -1;
        }
        
    }

    sort(a.begin() + 1, a.end());

    int sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        if (sum <= 0)
        {
            sum += a[i].a;
            a[i].b = 1;
        }
        else
        {
            sum -= a[i].a;
            a[i].b = -1;
        }
    }
    
    if (sum == 0)
    {
        sum += a[n - 1].b * a[n - 1].a;
        a[n - 1].b *= 2;
    }

    if (sum > 0 && a[n].op > 0 || sum < 0 && a[n].op < 0)
    {
        a[n].op = -1;
    }
    else
    {
        a[n].op = 1;
    }

    sum = abs(sum);
    a[n].a = abs(a[n].a);

    int g = __gcd(sum, a[n].a);
    sum /= g;
    a[n].a /= g;
    a[n].b = sum;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n - 1; i++)
    {
        a[i].b *= a[n].a;
        ans[a[i].i] = a[i].op * a[i].b;
    }
    ans[a[n].i] = a[n].op * a[n].b;

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';

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