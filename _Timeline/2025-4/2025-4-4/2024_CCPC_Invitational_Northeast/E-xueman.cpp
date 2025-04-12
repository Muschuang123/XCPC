#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int maxn = 2e5 + 10;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int tot = count(s.begin(), s.end(), '1');
        string ans = "";
        for (int i = tot, j = 0; j <= m; j++, i++)
        {
            string t = "";
            for (int k = 0; k < m; k++)
            {
                t += ((i >> k) & 1) + '0';
            }
            reverse(t.begin(), t.end());
            //cerr << t << endl;
            if (count(t.begin(), t.end(), '1') == j)
            {
                if (ans == "")
                    ans = t;
                else
                    ans = min(ans, t);
            }
        }
        if (ans == "")
            cout << "None" << endl;
        else
            cout << ans << endl;
    }
}