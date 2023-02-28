#include<iostream>
using namespace std;

int dp[205][10];//dp[i][j]表示数i分成j份的方案数
 
int main()
{
	int n,k;cin>>n>>k;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i&&j<=k;j++)
			dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
	cout<<dp[n][k];
	return 0;
}