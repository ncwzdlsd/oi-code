#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
int dep[maxn],head[maxn],cnt;
struct node{int to,nxt;}e[maxn*2];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    dep[x]=dep[fa]+1;
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
    }
}

int main()
{
    int n,d;cin>>n>>d;
    for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
    dfs(1,0);
    int ans=0;
    for(int i=2;i<=n;i++) if(dep[i]-1<=d) ans++;
    cout<<ans;
    return 0;
}