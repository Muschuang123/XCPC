#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string a, b;
    cin >> a >> b;
    int az = a.size(), bz = b.size();
    a = " " + a;
    b = " " + b;

    vector<int> sum(bz + 1);
    for (int i = 1; i <= bz; i++)
        sum[i] = sum[i - 1] + (b[i] - '0');
    
    int ans = 0;
    for (int i = 1; i <= az; i++)
    {
        if (a[i] == '0')
            ans += sum[bz - (az - i)] - sum[i - 1];
        else 
            ans += bz - (az - i) - (i - 1) - (sum[bz - (az - i)] - sum[i - 1]);
    }
    cout << ans;

    return 0;
}