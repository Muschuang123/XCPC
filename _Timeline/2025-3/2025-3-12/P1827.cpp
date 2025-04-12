#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> g[200005];
string s1, s2;

void dfs(string &l, string &r, char fa)
{
    if (l.empty())
        return;
    char p = l.front();
    g[fa].push_back(p);
    int k = r.find(p);
    string l1 = l.substr(1, k);
    string r1 = r.substr(0, k);
    dfs(l1, r1, p);
    string l2 = l.substr(k + 1);
    string r2 = r.substr(k + 1);
    dfs(l2, r2, p);
    cout << p;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> s1 >> s2;
    dfs(s2, s1, 0);
    

    return 0;
}