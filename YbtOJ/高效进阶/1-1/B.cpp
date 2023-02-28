#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[30][30];//表示传了j次在第i个人手中的方案数

signed main()
{
	int n,m;cin>>n>>m;
	f[1][0]=1;
	// 注意这里要先枚举m再枚举n，对于第j次的状态，和j-1有关
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			if(i==1) f[i][j]=f[n][j-1]+f[i+1][j-1];
			else if(i==n) f[i][j]=f[1][j-1]+f[i-1][j-1];
			else f[i][j]=f[i-1][j-1]+f[i+1][j-1];
			
		}
	cout<<f[1][m];
	return 0;
}