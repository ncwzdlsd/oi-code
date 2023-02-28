#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=10005,inf=0x7fffffff;
int a[maxn],qwq[maxn],sum[maxn],n,dp[2][500010],maxa;

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) qwq[i]=a[i+1]-a[i];
	sort(qwq+1,qwq+n),maxa=a[n];int cnt=1;
	for(int i=1;i<n;i++) if(!qwq[i]) cnt++;
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+qwq[i];
	int now=0,last=1,lim=maxa*n;
	for(int i=0;i<=lim;i++) dp[now][i]=inf; 
	dp[now][qwq[cnt]]=qwq[cnt]*qwq[cnt]; 
	dp[now][qwq[cnt]*cnt]=qwq[cnt]*qwq[cnt]*cnt; 
	for(int i=cnt+1;i<n;i++)
	{
		now^=1,last^=1;
		for(int j=0;j<=lim;j++) dp[now][j]=inf;
		for(int j=0;j<=lim;j++)
		{
			if(dp[last][j]==inf) continue;
			dp[now][j+qwq[i]*i]=min(dp[now][j+qwq[i]*i],dp[last][j]+2*j*qwq[i]+qwq[i]*qwq[i]*i);
			dp[now][j+sum[i]]=min(dp[now][j+sum[i]],dp[last][j]+sum[i]*sum[i]); 
		}
	}
	int ans=inf;
	for(int i=0;i<=maxa*n;i++)
		if(dp[now][i]!=inf) ans=min(ans,n*dp[now][i]-i*i);
	cout<<ans;
	return 0;
}