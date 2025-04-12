#include <bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
int t;
    cin >> t;
    while (t--){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
 
        if ( a<=n&& b<= n && c <= n && a+b+c<=2*n &&
           a+b+c>=n )
            cout << "Yes\n";
        else 
            cout << "No\n";
 
    }
    
    return 0;
}