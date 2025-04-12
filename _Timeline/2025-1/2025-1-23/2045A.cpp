#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    vector<int> a(130);
    for (auto &c : s)
    {
        a[c]++;
    }

    int ae = 0, y = 0, ng = 0, oth = 0;
    ae = a['A'] + a['E'] + a['I'] + a['O'] + a['U'];
    y = a['Y'];
    ng = min(a['N'], a['G']);
    oth = s.size() - ae - y;

    while (y > 0 && ae * 2 < oth)
    {
        ae++;
        y--;
    }
    while (y > 0 && oth < ae * 2)
    {
        oth++;
        y--;
    }

    oth += y / 3 * 2;
    ae += y / 3 * 1;
    y %= 3;
    oth += y;
    y = 0;

    if (ae * 2 < oth)
    {
        cout << ae * 3 + min({oth - ae * 2, ng, ae * 2});
    }
    else
    {
        if (oth % 2 && ng)
            cout << oth / 2 * 3 + 1;
        else 
            cout << oth / 2 * 3;
    }


    return 0;
}