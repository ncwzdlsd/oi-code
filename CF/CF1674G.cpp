#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
struct edge{int to,nxt;}e[maxn];
int head[maxn],f[maxn],in[maxn],out[maxn],cnt;

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    if(f[x]) return;
    f[x]=1;
    if(out[x]<2) return;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
        if(in[e[i].to]>1) f[x]=max(f[x],f[e[i].to]+1);
    }
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1,u,v;i<=m;i++) cin>>u>>v,add(u,v),in[v]++,out[u]++;
    for(int i=1;i<=n;i++) dfs(i,0);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans;
    return 0;
}