#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int head[maxn],cnt,in[maxn],fa[maxn],N;
struct edge{int to,nxt;}e[maxn*2];
bool vis[maxn];
queue<int> q;

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void topo()
{
    for(int i=1;i<=N;i++) if(in[i]==1) q.push(i),vis[i]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt)
        {
            in[e[i].to]--;
            if(in[e[i].to]==1) q.push(e[i].to),vis[e[i].to]=1;
        }
    }
    for(int i=1;i<=N;i++) if(!vis[i]) cout<<i<<' ';
}

int main()
{
    cin>>N;
    for(int i=1,a,b;i<=N;i++) cin>>a>>b,add(a,b),add(b,a),in[b]++,in[a]++;
    topo();
    return 0;
}