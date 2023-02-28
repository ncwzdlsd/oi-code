#include <bits/stdc++.h>
using namespace std;

int head[6005],to[6005],nxt[6005],N,M,wei[6005],f[3005][3005],siz[6005],cnt;

void add(int x,int y,int z)
{
	to[++cnt]=y;
	wei[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x)
{
	for(int i=head[x];i;i=nxt[i])
	{
		dfs(to[i]);
		siz[x]+=siz[to[i]];
		for(int j=siz[x];j>=1;j--)
			for(int k=1;k<=min(j,siz[to[i]]);k++)
				f[x][j]=max(f[x][j],f[x][j-k]+f[to[i]][k]-wei[i]);
	}
}

int main()
{
	memset(f,-0x3f,sizeof(f));
	cin>>N>>M;
	for(int i=1;i<=N-M;i++)
	{
		int K;cin>>K;
		for(int j=1;j<=K;j++)
		{
			int weight,v;
			cin>>v>>weight;
			add(i,v,weight);
		}
	}
	for(int i=N-M+1;i<=N;i++) cin>>f[i][1],siz[i]=1;
	for(int i=1;i<=N;i++) f[i][0]=0;
	dfs(1);
	for(int i=M;i>=0;i--) if(f[1][i]>=0) {cout<<i;return 0;}
	return 0;
}