#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    Bicarp 想赢非常难。
    不仅要让问号的一边总和少，还要让所有的问号放完后精准的让两边相等。
    而所有的问号在放的过程中，Monocarp 肯定想赢，所以就全放 0 或者全放 9
    除非对于这两种策略 Bicarp 都能保证稳赢，否则就完蛋。
    保证都稳赢的话，必须让两个人放的数量稳定在 9（其他的数不能稳定）
    所以 Bicarp 只能通过这种方式赢： 两个问号加起来是 9，这样放完之后，两边和恰好相等。
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int sum1 = 0, sum2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if (s[i] == '?')
            cnt1++;
        else
            sum1 += s[i] - '0';
    }

    for (int i = n / 2 + 1; i <= n; i++)
    {
        if (s[i] == '?')
            cnt2++;
        else
            sum2 += s[i] - '0';
    }

    if (cnt1 < cnt2)
    {
        swap(cnt1, cnt2);
        swap(sum1, sum2);
    }

    int cnt = cnt1 - cnt2;

    if (sum1 > sum2)
    {
        cout << "Monocarp";
    }
    else // sum1 <= sum2
    {
        if (sum1 + cnt / 2 * 9 == sum2)
        {
            cout << "Bicarp";
        }
        else
        {
            cout << "Monocarp";
        }
    }

    return 0;
}