#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,s[21][N],f[(1<<20)];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		for(int j=1;j<=m;j++)s[j][i]=s[j][i-1];
		s[x][i]++;
	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=0;i<(1<<m);i++)
	{
		int cnt=0;
		for(int j=0;j<m;j++)
			if(i&(1<<j)) cnt+=s[j+1][n];
		for(int j=0;j<m;j++)
		{
			if(!(i&(1<<j)))continue;
			int pre=cnt-s[j+1][n],now=cnt,sta=(i^(1<<j));
			f[i]=min(f[i],f[sta]+s[j+1][n]-(s[j+1][now]-s[j+1][pre]));
		}
	}
	printf("%d",f[(1<<m)-1]);
	return 0;
} 