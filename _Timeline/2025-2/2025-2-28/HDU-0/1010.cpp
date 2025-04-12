#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = abs(a[i]); 
        a[i] += a[i - 1];
    }
    cout << accumulate(a.begin() + 1, a.end(), 0LL);

    return 0;
}