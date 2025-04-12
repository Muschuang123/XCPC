#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
    for every pair of string can palindrome,
        only their combination have the number of odd characters <= 1.
    
    just brute force.

    use the unordered_map to store the hash of string.
        it could be O(1) to find the string.
*/

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    unordered_map<string, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        string ts;
        cin >> ts;
        vector<int> buc(26);
        for (auto &c : ts)
        {
            buc[c - 'a']++;
        }

        set<char> ss;
        for (int j = 0; j < 26; j++)
        {
            if (buc[j] % 2 == 0)
            {
                ss.insert(j + 'a');
            }
        }

        string s;
        for (int j = 0; j < 26; j++)
        {
            s.clear();
            if (ss.count(j + 'a'))
            {
                ss.erase(j + 'a');
                for (auto &c : ss)
                    s.push_back(c);
                if (mp.count(s))
                    ans += mp[s];
                ss.insert(j + 'a');
            }
            else
            {
                ss.insert(j + 'a');
                for (auto &c : ss)
                    s.push_back(c);
                if (mp.count(s))
                    ans += mp[s];
                ss.erase(j + 'a');
            }
        }
        
        s.clear();
        for (auto &c : ss)
            s.push_back(c);
        if (mp.count(s))
            ans += mp[s];
        
        mp[s]++;
    }

    cout << ans << '\n';

    return 0;
}