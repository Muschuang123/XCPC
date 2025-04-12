#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> x(n + 1), y(n + 1);
    vector<int> fir(n + 1), sec(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i] + y[i] >= c)
            fir[i] = 1;
    }
    int d;
    cin >> d;

    for (int i = 1; i <= n; i++)
    {
        x[i] = min(a, x[i] + d);
        if (x[i] + y[i] >= c)
            sec[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!fir[i] && sec[i])
            cnt++;
    }
    cout << cnt;

    return 0;
}