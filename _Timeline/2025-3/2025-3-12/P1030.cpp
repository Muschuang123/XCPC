#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

/*
BADC mid 
BDCA suf
ABCD pre
*/

void dfs(string &mid, string &suf)
{
    if (mid.empty())
        return;
    char p = suf.back();
    suf.pop_back();
    cout << p;
    int n = mid.size();
    int k = mid.find(p);
    string leftMid = mid.substr(0, k);
    string rightMid = mid.substr(k + 1);
    string leftSuf = suf.substr(0, k);
    string rightSuf = suf.substr(k);
    dfs(leftMid, leftSuf);
    dfs(rightMid, rightSuf);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    dfs(s1, s2);

    return 0;
}