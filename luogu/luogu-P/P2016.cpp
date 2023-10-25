#include <bits/stdc++.h>
using namespace std;

const int maxn=3005;
struct edge{int to,nxt;}e[maxn];
int head[maxn],cnt,f[maxn][2];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	f[x][0]=0,f[x][1]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(e[i].to==fa) continue;
		dfs(e[i].to,x);
		f[x][0]+=f[e[i].to][1],f[x][1]+=min(f[e[i].to][0],f[e[i].to][1]);
	}
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int ii,k,u;cin>>ii>>k;
		while(k--) cin>>u,add(ii+1,u+1),add(u+1,ii+1); 
	}
	dfs(1,0);
	cout<<min(f[1][0],f[1][1]);
	return 0;
}