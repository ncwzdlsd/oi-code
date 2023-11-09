#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+5;
int head[maxn],V,cnt,mxd[maxn];
struct edge{int to,nxt,w;}e[maxn];

void add(int x,int y,int z){e[++cnt]=(edge){y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x),mxd[x]=max(mxd[x],mxd[e[i].to]+e[i].w);
    }
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        V+=mxd[x]-(mxd[e[i].to]+e[i].w);
    }
}

signed main()
{
    int N,S;cin>>N>>S;
    for(int i=1,a,b,t;i<N;i++) cin>>a>>b>>t,add(a,b,t),add(b,a,t);
    dfs(S,0);
    cout<<V;
    return 0;
}