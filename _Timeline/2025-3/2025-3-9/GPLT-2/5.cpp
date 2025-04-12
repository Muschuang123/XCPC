#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m;
    cin >> m;
    vector<string> a(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }

    int k;
    cin >> k;
    cin.ignore(100, '\n');
    int cnt = 0;
    string s;
    getline(cin, s);
    int n = s.size();
    string sp;
    for (int j = 1; j <= m; j++)
    {
        sp = "";
        for (int i = 0; i < n; i++)
        {
            if (i - 1 + (int)a[j].size() < n && s.substr(i, a[j].size()) == a[j])
            {
                sp += "\n";
                i += a[j].size();
                i--;
                cnt++;
            }
            else
            {
                sp += s[i];
            }
        }
        s = sp;
        n = s.size();
    }

    if (cnt < k)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '\n')
            {
                cout << "<censored>";
            }
            else
            {
                cout << s[i];
            }
        }
    }
    else
    {
        cout << cnt << '\n';
        cout << "He Xie Ni Quan Jia!" << '\n';
    }

    return 0;
}