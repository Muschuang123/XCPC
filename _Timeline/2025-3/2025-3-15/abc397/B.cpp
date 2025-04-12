#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // length < 100
    string s;
    cin >> s;
    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (i % 2)
        {
            if (s[i] != 'o')
            {
                s.insert(i, "o");
                cnt++;
            }
        }
        else
        {
            if (s[i] != 'i')
            {
                s.insert(i, "o");
                cnt++;
            }
        }
    }
    if (s.size() % 2)
        cnt++;
    cout << cnt << '\n';

    return 0;
}