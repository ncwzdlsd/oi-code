#include<bits/stdc++.h>
using namespace std;
 
const int MAXN=200005;
struct city
{
    int x,y;
    bool operator < (const city a) const 
    {
        return x<a.x;
    }
}c[MAXN];
int a[MAXN],dp[MAXN],cnt=0;
 
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>c[i].x>>c[i].y;
    sort(c,c+n);
    for(int i=0;i<n;++i)
        a[i]=c[i].y;
    dp[0]=a[0];
    for(int i=1;i<n;++i)
    {
        if(a[i]>dp[cnt]) dp[++cnt]=a[i];
        else
            dp[lower_bound(dp,dp+cnt+1,a[i])-dp]=a[i];
    }
    cout<<cnt+1<<endl;
    return 0;
}