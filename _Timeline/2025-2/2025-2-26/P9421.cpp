#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int cntd = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt1 += a[i] == 1;
        cntd += max(2, a[i]) - 2;
    }
    if (cntd > cnt1)
    {
        cout << cntd - cnt1;
    }
    else
    {
        cout << (cnt1 + cntd) / 2;
    }

    return 0;
}