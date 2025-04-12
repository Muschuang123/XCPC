#include<bits/stdc++.h>
#define int long long
using namespace std;

set<string> word;
string s;
int n;

string change(string s){
    int len = s.size();
    for(int i=0;i<len;i++)
        if(s[i] >= 'A' and s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
    return s;
}

signed main(){
    getline(cin,s);
    s = s+" ";
    int len = s.size();
    string t = "\0";
    for(int i=0;i<len;i++){
        if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')){
            t = t+s[i];
        }
        else{
            if(t == "") continue;

            t = change(t);
            word.insert(t);
            //cout<<t<<endl;
            t = "";
        }
    }

    scanf("%lld",&n);
    getchar();
    getline(cin,s);
    s = s+" ";

    len = s.size();
    t = "\0";
    for(int i=0;i<len;i++){
        if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')){
            t = t+s[i];
        }
        else{
            if(t == "") continue;
            
            t = change(t);
            //cout<<t<<endl;
            word.erase(t);
        }
    }
    printf("%lld",word.size());
}