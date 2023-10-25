#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f;
const int N=210;
const int M=20005;
int f[N][N],vis[N];
int n,m,Q,t[N];
int main()
{
	memset(f,inf,sizeof(f));
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>t[i],f[i][i]=0;;
	int u,v,w;
	for(int i=1;i<=m;i++) cin>>u>>v>>w;,f[u][v]=f[v][u]=w;
	cin>>Q;
	while(Q--)
	{
		scanf("%d%d%d",&u,&v,&w);
		for(int k=0;k<n;k++)
		{
			if(t[k]<=w&&!vis[k])
			{
				vis[k]=1;
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++)
						if(f[i][j]>f[i][k]+f[k][j])
							f[i][j]=f[i][k]+f[k][j];
			}
		}
		if (t[u]<=w&&t[v]<=w&&f[u][v]<inf) printf("%d\n",f[u][v]);
        else printf("-1\n");
	}
	return 0;
}