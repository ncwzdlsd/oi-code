#include <bits/stdc++.h>
using namespace std;

const int maxn=10005;
struct edge{int to,nxt;}e[maxn*2];
int head[maxn],cnt,dep[maxn];

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
    }
}

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1,u,v;i<=m;i++) cin>>u>>v,add(u,v),add(v,u);
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        sum1=0,sum2=0;
        dfs(i,0);
        for(int j=1;j<=n;j++)
        {
            if(dep[j]==2) sum1++;
            if(dep[j]==3) sum2++;
            if(dep[j]>3){flag=0;break;}
        }
        if(flag) break;
    }
    cout<<sum1<<' '<<sum2/sum1<<endl;
    memset(head,0,sizeof head),memset(e,0,sizeof e),cnt=0;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}