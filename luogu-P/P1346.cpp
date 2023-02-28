#include <bits/stdc++.h>
using namespace std;

const int maxn=105,inf=1e8;
int g[maxn][maxn];

int main()
{
	int N,A,B,K,a;cin>>N>>A>>B;
	for(int i=1;i<=N;i++)
	    for(int j=1;j<=N;j++)
	    	g[i][j]=inf,g[i][i]=0;
	for(int i=1;i<=N;i++)
	{
		cin>>K;
		for(int j=1;j<=K;j++)
		{
			cin>>a;
			if(j==1) g[i][a]=0;
			else g[i][a]=1;
		}
	}
	for(int k=1;k<=N;k++)
		for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	if(g[A][B]==inf) puts("-1");
	else cout<<g[A][B];
	return 0;
}