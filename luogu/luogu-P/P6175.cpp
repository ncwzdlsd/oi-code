#include<bits/stdc++.h>
#define ff(i,s,e) for(int i=s;i<=e;i++)
#define fff(i,s,e) for(int i=s;i>=e;i--)
using namespace std;
const int M=1e3*5+5;
int n,m,ans=0x3f3f3f;
int deg[M],d[M][M],nxt[M][M];
bool vis[M][M];
void dfs(int st,int x,int len,int tot)
{
    if(len>ans) return;
    ff(i,1,deg[x])
    {
        if(nxt[x][i]==st&&tot>=3)
        {
            ans=min(ans,len+d[x][nxt[x][i]]);
            return;
        }
        if(!vis[x][nxt[x][i]])
        {
            vis[x][nxt[x][i]]=vis[nxt[x][i]][x]=1;
            dfs(st,nxt[x][i],len+d[x][nxt[x][i]],tot+1);
            vis[x][nxt[x][i]]=vis[nxt[x][i]][x]=0;
        }
    }
}
int main(){
    cin>>n>>m;
    int u,v,dd;
    ff(i,1,m)
    {
        cin>>u>>v>>dd;
        if(d[u][v]==0) d[u][v]=d[v][u]=dd,nxt[u][++deg[u]]=v,nxt[v][++deg[v]]=u;
        else d[u][v]=d[v][u]=min(d[u][v],dd);
    }
    ff(i,1,n)
        if(deg[i])
            dfs(i,i,0,1);
    if(ans!=0x3f3f3f) printf("%d",ans);
    else printf("No solution.");
    return 0;
}