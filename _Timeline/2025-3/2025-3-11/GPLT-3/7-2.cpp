#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    if (m == 0)
        h--;
    if (h <= 11)
    {
        cout << "Only " + s + ".  Too early to Dang.";
    }
    else
    {
        for (int i = 12; i <= h; i++)
        {
            cout << "Dang";
        }
    }

    return 0;
}