string s1, s2;
cin >> s1 >> s2;
int n = s1.size(), m = s2.size();
s1 = " " + s1;
s2 = " " + s2;
// s1.substr(ok[i], s2.size()) == s2
vector<int> ok;

vector<int> ne(m + 1);
for (int i = 2, j = 0; i <= m; i++) {
    while (j > 0 && s2[j + 1] != s2[i]) j = ne[j];
    if (s2[j + 1] == s2[i]) j++;
    ne[i] = j;
}
for (int i = 1, j = 0; i <= n; i++) {
    while (j > 0 && s2[j + 1] != s1[i]) j = ne[j];
    if (s2[j + 1] == s1[i]) j++;
    if (j == m) {
        ok.push_back(i - j + 1);
        j = ne[j];
    }
}