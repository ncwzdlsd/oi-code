#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005],s[305][305];
int main()
{
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    ll n,m,ans=-1e9;
    cin>>n>>m;
    f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            ll t;cin>>t;
            if(t==0)t=-1e9;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+t;
        }
    for(int i=1;i<=n;i++)
        for(int k=i;k<=n;k++)
            for(int j=1;j<=m;j++)
            {
                ll t=s[k][j]-s[i-1][j]-s[k][j-1]+s[i-1][j-1];
                f[j]=t+max(0ll,f[j-1]);
                ans=max(ans,0ll);
            }
    cout<<ans;
}