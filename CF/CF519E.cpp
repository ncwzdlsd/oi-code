#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
int dep[maxn],f[maxn][25],head[maxn],cnt,siz[maxn];
struct edge{int to,nxt;}e[maxn*2];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1,f[x][0]=fa,siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
        siz[x]+=siz[e[i].to];
    }
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}

int jump(int x,int d)
{
    int res=x;
    for(int i=20;i>=0;i--) if(dep[x]-dep[f[res][i]]<=d) res=f[res][i];
    return res;
}

void query(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    if(x==y) return cout<<siz[1]<<'\n',void();
    int l=dep[x]+dep[y]-2*dep[lca(x,y)];
    if(l%2) return cout<<"0\n",void();
    l/=2;
    if(dep[x]==dep[y]) return cout<<(siz[1]-siz[jump(x,l-1)]-siz[jump(y,l-1)])<<endl,void();
    else return cout<<(siz[jump(x,l)]-siz[jump(x,l-1)])<<endl,void();
}

int main()
{
    int n;cin>>n;
    for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
    dfs(1,0);
    for(int j=1;j<=20;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
    int m;cin>>m;
    for(int i=1,x,y;i<=m;i++) cin>>x>>y,query(x,y);
    return 0;
}    