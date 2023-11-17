#include <bits/stdc++.h>
using namespace std;

const int maxn=5005,maxm=1e4+5;
int head[maxn],cnt,tot[maxn],dis[maxn],n,m;
bool vis[maxn];
struct edge{int to,nxt,w;}e[maxm];

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

bool spfa(int s)
{
    queue<int> q;
    memset(dis,-0x3f3f3f,sizeof dis);
    dis[s]=0,q.push(s),vis[s]=1,tot[s]++;
    while(!q.empty())
    {
        int x=q.front();q.pop(),vis[x]=0;
        for(int i=head[x];i;i=e[i].nxt)
            if(dis[e[i].to]<dis[x]+e[i].w)
            {
                dis[e[i].to]=dis[x]+e[i].w;
                if(!vis[e[i].to]) vis[e[i].to]=1,q.push(e[i].to),tot[e[i].to]++;
                if(tot[e[i].to]>=n) return 0;
            }
    }
    return 1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int op;cin>>op;
        if(op==1)
        {
            int a,b,c;cin>>a>>b>>c;
            add(b,a,c);
        }
        else if(op==2)
        {
            int a,b,c;cin>>a>>b>>c;
            add(a,b,-c);
        }
        else
        {
            int a,b;cin>>a>>b;
            add(a,b,0),add(b,a,0);
        }
    }
    for(int i=1;i<=n;i++) add(0,i,0);
    if(spfa(1)) cout<<"Yes";
    else cout<<"No";
    return 0;
}