#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int sta[maxn],idx,val[maxn],dp[maxn],p[maxn]/*p记录缩点集合*/,mx[maxn];
vector<int> g1[maxn],g2[maxn],g3[maxn]/*缩点图*/;
bool vis[maxn];

void dfs1(int x)
{
    vis[x]=1;
    int len=g1[x].size();
    for(int i=0;i<len;i++) if(!vis[g1[x][i]]) dfs1(g1[x][i]);
    sta[++idx]=x;
}

void dfs2(int x,int fa)
{
    vis[x]=0;p[x]=fa;
    mx[fa]=max(val[x],mx[fa]);
    int len=g2[x].size();
    for(int i=0;i<len;i++) if(vis[g2[x][i]]) dfs2(g2[x][i],fa);
}

int dfs(int x)
{
	if(dp[x]) return dp[x];
    dp[x]=mx[x];
    int len=g3[x].size();
    for(int i=0;i<len;i++)
        dp[x]=max(dp[x],dfs(g3[x][i]));
    return dp[x];
}

int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>val[i];
	while(m--) 
	{
		int a,b;cin>>a>>b;
		g1[a].push_back(b);
		g2[b].push_back(a);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs1(i);
    for(int i=n;i;i--) if(vis[sta[i]]) dfs2(sta[i],sta[i]);
    for(int i=1;i<=n;i++)
    {
        int len=g1[i].size();
        for(int j=0;j<len;++j)
        {
            if(p[i]==p[g1[i][j]]) continue;
            g3[p[i]].push_back(p[g1[i][j]]);
        }
    }
    for(int i=1;i<=n;i++) cout<<dfs(p[i])<<' '; 
	return 0;
} 
