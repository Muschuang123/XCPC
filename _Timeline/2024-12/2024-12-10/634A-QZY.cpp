#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a[5100],ans[5100],b[5100];
int n;
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        int maxx=0;int maxi=0;
        for(int j=i;j<=n;j++)
        {
            b[a[j]]++;
            if(maxx<b[a[j]])
            {
                maxx=b[a[j]];
                maxi=a[j];
            }
            if(maxx==b[a[j]]&&maxi>a[j])
            {
                maxx=b[a[j]];
                maxi=a[j];
            } 
            ans[maxi]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}