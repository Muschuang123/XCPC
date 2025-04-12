#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = 100;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = 2 * i - 2;
        s[i] = s[i - 1] + a[i];
    }

    set<int> ss;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ss.insert(s[j] - s[i - 1]);
        }
    }
    
    int cnt = 0;
    for (auto &v : ss)
    {
        if (cnt > 100)
            break;
        cout << v << '\n';
        cnt++;
    }

    return 0;
}