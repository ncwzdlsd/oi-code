#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0x3f3f3f;
int a[105],b[105],dp[55005];
int main()
{
	cin>>n>>m;
    for(int i=1;i<=m+5000;i++) dp[i]=0x3f3f3f;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=a[i];j<=m+5000;j++)
        	dp[j]=min(dp[j],dp[j-a[i]]+b[i]);
    for(int i=m;i<=m+5000;i++)
    	ans=min(ans,dp[i]); 
	cout<<ans;
	return 0;
}