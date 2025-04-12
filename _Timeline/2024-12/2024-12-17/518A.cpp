#include <bits/stdc++.h>
#define int long long
using namespace std;

char chang(char c)
{
    if (c < 'z')
        c = c + 1;
    else 
        c = 'a';
    return c;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    string ans;
    bool fl = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans.push_back(s[i]);
        if (s[i] != t[i])
            fl = 1;
    }

    char c = chang(s[n - 1]);
    ans.push_back(c);
    if (c == 'a')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] != t[i])
            {
                ans[i] = chang(s[i]);
                if (ans[i] != 'a')
                    break;
            }
        }
    }
    
    if (ans == t)
        cout << "No such string";
    else 
        cout << ans;

    return 0;
}