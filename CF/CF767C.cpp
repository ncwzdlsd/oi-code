#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e6+5;
int t[maxn],head[maxn],cnt,siz[maxn],sum,ans[maxn],tot;
struct edge{int to,nxt;}e[maxn*2];

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    siz[x]=t[x];
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
        siz[x]+=siz[e[i].to];
    }
    if(siz[x]==sum) ans[++tot]=x,siz[x]=0;
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int rt=0;
    for(int i=1;i<=n;i++)
    {
        int a;cin>>a>>t[i],sum+=t[i];
        if(!a) rt=i;
        else add(a,i),add(i,a);
    }
    if(sum%3) cout<<"-1",exit(0);    
    sum/=3;
    dfs(rt,0);
    if(tot<3) cout<<"-1";
    else cout<<ans[1]<<' '<<ans[2];
    return 0;
}