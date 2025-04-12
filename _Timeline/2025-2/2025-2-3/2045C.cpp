#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    vector<int> sc(26), tc(26);
    for (int i = 1; i < s.size(); i++)
    {
        if (!sc[s[i] - 'a'])
            sc[s[i] - 'a'] = i;
    }

    reverse(t.begin(), t.end());
    for (int i = 1; i < t.size(); i++)
    {
        if (!tc[t[i] - 'a'])
            tc[t[i] - 'a'] = i;
    }    
    for (int i = 0; i < 26; i++)
    {
        if (sc[i] && tc[i])
            sc[i] += tc[i];
        else   
            sc[i] = 0;
    }
    int mi = 0x3f3f3f3f;
    char mic = ' ';
    for (int i = 0; i < 26; i++)
    {
        if (sc[i] && mi > sc[i])
        {
            mi = sc[i];
            mic = i + 'a';
        }
    }

    if (mic == ' ')
    {
        cout << -1 << '\n';
        return 0;
    }

    string ans;
    ans.push_back(s[0]);
    for (int i = 1; i < s.size() && s[i] != mic; i++)
    {
        ans.push_back(s[i]);
    }
    for (int i = tc[mic - 'a']; i >= 0; i--)
    {
        ans.push_back(t[i]);
    }

    cout << ans;

    return 0;
}