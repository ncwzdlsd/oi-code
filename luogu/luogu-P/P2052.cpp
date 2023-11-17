#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
struct edge{int to,nxt,w;}e[maxn*2];
int head[maxn],cnt,siz[maxn],ans,n;

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
    siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
        siz[x]+=siz[e[i].to];
        ans+=e[i].w*abs(siz[e[i].to]*2-n);
    }
}

signed main()
{
    cin>>n;
    for(int i=1,a,b,c;i<n;i++) cin>>a>>b>>c,add(a,b,c),add(b,a,c);
    dfs(1,0);
    cout<<ans;
    return 0;
}