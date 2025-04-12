#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vec.push_back(i);
        }
    }
    if (vec.size() < k || (int)vec.size() % k != 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    i64 ans = 1;
    for (int i = k; i < vec.size(); i += k)
    {
        ans = (ans * (vec[i] - vec[i - 1])) % mod;
    }
    cout << ans << '\n';

    return 0;
}