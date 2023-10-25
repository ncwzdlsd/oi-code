#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int n,ch[maxn][2],val[maxn],sz[maxn];
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]

void dfs(int u)
{
    sz[u]=1;
    if(ls(u)!=-1)
        dfs(ls(u)),sz[u]+=sz[ls(u)];
    if(rs(u)!=-1)
        dfs(rs(u)),sz[u]+=sz[rs(u)];
}

bool solve(int u,int v)
{
    if(u==-1&&v==-1)return 1;
    if(u==-1||v==-1)return 0;
    return val[u]==val[v]&&solve(ls(u),rs(v))&&solve(rs(u),ls(v));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<=n;i++)
        cin>>ls(i)>>rs(i);
    dfs(1);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(solve(ls(i),rs(i)))
            ans=max(ans,sz[i]);
    cout<<ans;
    return 0;
}
