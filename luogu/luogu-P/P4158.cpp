#include <bits/stdc++.h>
using namespace std;

int f[55][2505],sum[55][2505],g[55][2505][55];
char s[105];

int main()
{
	int N,M,T,ans=0;cin>>N>>M>>T;
	for(int i=1;i<=N;i++) 
	{
		cin>>s;
		sum[i][0]=0;//前缀和初始化
		for(int j=1;j<=M;j++)
		{
			if(s[j-1]=='1') sum[i][j]=sum[i][j-1]+1;//记录当前条的蓝色格子数
			else sum[i][j]=sum[i][j-1];		
		}
	}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			for(int k=1;k<=M;k++)
				for(int r=j-1;r<k;r++)
					g[i][j][k]=max(g[i][j][k],g[i][j-1][r]+max(sum[i][k]-sum[i][r],k-r-sum[i][k]+sum[i][r]));
	for(int i=1;i<=N;i++)
		for(int j=1;j<=T;j++)
			for(int k=1;k<=min(j,M);k++)
				f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][M]);
	for(int i=1;i<=T;i++) ans=max(ans,f[N][i]);
	cout<<ans;
	return 0;
}