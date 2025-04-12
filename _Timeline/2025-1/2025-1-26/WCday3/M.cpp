#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main (){
    
    string s;
    cin>> s;
    vector<int> a(130);
    for (auto &c : s)
        a[c]++;
    
    if (a[99] &&a[100]&&
        a[101] &&a[110]&&
        a[111]>=2 && a[114] && a[119])
        cout << "happy new year";
    else
        cout << "I AK IOI";


    
    return 0;
    }