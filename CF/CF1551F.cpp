#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;
int head[105],f[105][105],c[105],dep[105],cnt;
struct edge{int to,nxt;}e[205];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1,c[dep[x]]++;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
    }
}

void solve()
{
    int n,k;cin>>n>>k;
    cnt=0;
    for(int i=1;i<=n;i++) head[i]=0,dep[i]=0;
    for(int i=1;i<=n*2;i++) e[i]={0,0};
    for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
    if(k==2) return cout<<n*(n-1)/2<<endl,void();
    int ans=0;
    for(int rt=1;rt<=n;rt++)
    {
        dep[rt]=0;
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
        for(int i=0;i<=n;i++) f[i][0]=1;
        for(int kk=head[rt];kk;kk=e[kk].nxt)
        {
            for(int i=0;i<=n;i++) c[i]=0;
            dfs(e[kk].to,rt);
            // for(int i=1;i<=n;i++) c[dep[i]]++;
            for(int i=1;i<=n;i++)
            {
                if(!c[i]) break;
                for(int j=k;j;j--) f[i][j]+=f[i][j-1]*c[i]%mod,f[i][j]%=mod;
                // if(rt==2) for(int j=k;j;j--) cout<<f[i][j]<<endl;
            }
        }  
        for(int i=1;i<=n;i++) ans+=f[i][k],ans%=mod;
        // cout<<ans<<"qwq\n";
        // for(int i=1;i<=n;i++) cout<<c[2]<<endl;
        // puts("");
    }
    cout<<ans<<'\n';
}

signed main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}