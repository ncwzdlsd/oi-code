#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
int head[maxn],cnt,s[maxn];
struct edge{int to,nxt,w;}e[maxn*2];

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].nxt)
    {
        if(e[i].to==fa) continue;
        s[e[i].to]=s[x]^e[i].w;
        dfs(e[i].to,x);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1,u,v,w;i<n;i++) cin>>u>>v>>w,add(u,v,w),add(v,u,w);
    dfs(1,0);
    while(q--)
    {
        int x,y,l,r;cin>>x>>y>>l>>r;
        if((r-l+1)%2) cout<<(s[x]^s[y])<<'\n';
        else cout<<"0\n";
    }   
    return 0;
}