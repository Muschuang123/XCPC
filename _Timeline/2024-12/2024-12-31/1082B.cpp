#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    check the consistent 'G' in a row which can include a 'S'.
    use the two pointers.

    in this program, the state in r's loop is legal, but in l's loop is illegal.
    the key to control two pointers is that 
        judge the state is legal or not, and check answer.
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    
    int l = 1, r = 1;
    int ans = 0;
    int inc = 0;
    while (r <= n)
    {
        while (r <= n && inc <= 1)
        {
            ans = max(ans, r - l - inc);
            if (s[r] == 'S')
            {
                inc++;
            }
            r++;
        }

        while (inc > 1)
        {
            if (s[l] == 'S')
            {
                inc--;
            }
            l++;
        }
        ans = max(ans, r - l - inc);
        // cout << "";
    }
    
    // check another G

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'G')
            cnt++;
    }

    if (cnt > ans)
    {
        ans++;
    }

    cout << ans;

    return 0;
}