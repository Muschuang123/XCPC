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

    int p = s.size() - 1;
    while (s[p] == 'z')
    {
        p--;
    }
    s[p]++;
    p++;
    while (p < s.size())
    {
        s[p] = 'a';
        p++;
    }
    
    if (s == t)
        cout << "No such string";
    else 
        cout << s;

    return 0;
}