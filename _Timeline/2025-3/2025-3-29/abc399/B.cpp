#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int, greater<>> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int sum = 0;
    for (auto &[f, s] : mp)
    {
        int t = s;
        s = sum + 1;
        sum += t;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << mp[a[i]] << '\n';
    }


    return 0;
}