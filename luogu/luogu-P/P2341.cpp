#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
int head[maxn],to[maxn],nxt[maxn],cnt;
int dfn[maxn],sta[maxn]/*栈*/,low[maxn],dfncnt,siz[maxn],du[maxn],top/*记录栈中元素编号*/,sccnum/*记录强连通分量编号*/,scc[maxn]/*编号为i的点所在的强连通分量编号*/;
bool vis[maxn];

void add(int x,int y)
{
    to[++cnt]=y;
    nxt[cnt]=head[x];
    head[x]=cnt;
}

void tarjan(int u)
{
    low[u]=dfn[u]=++dfncnt;
    sta[++top]=u;vis[u]=1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v]) tarjan(v)/*继续往下搜*/,low[u]=min(low[u],low[v]);
        else if(vis[v]) low[u]=min(low[u],dfn[v]);  
    }
    if(dfn[u]==low[u])
    {
        ++sccnum;
        while(sta[top]!=u)//把它搜索树里的都弹完
            scc[sta[top]]=sccnum,vis[sta[top]]=0,siz[sccnum]++,top--;//数组模拟弹栈
        //处理它自己
        scc[sta[top]]=sccnum;
        vis[sta[top]]=0;
        siz[sccnum]++;
        top--;
    }
}

int main()
{
    int N,M,a,b;cin>>N>>M;
    for(int i=1;i<=M;i++)
        cin>>a>>b,add(a,b);
    for(int i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
    for(int i=1;i<=N;i++)
        for(int j=head[i];j;j=nxt[j])
            if(scc[to[j]]!=scc[i])
                du[scc[i]]++;
    int ans=0,cntt=0;
    for(int i=1;i<=sccnum;i++)
    {
        if(!du[i])
        {
            cntt++;
            if(cntt>1) {ans=0;break;}
	        ans+=siz[i];
        }
    }
    cout<<ans;
    return 0;
}