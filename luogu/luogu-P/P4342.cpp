#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
char c[maxn];
int dp1[maxn][maxn],dp2[maxn][maxn],x[maxn],a[maxn];

int main()
{
	int n;
	cin>>n;
	memset(dp2,127,sizeof(dp2));
	memset(dp1,128,sizeof(dp1));
	for (int i=1;i<=n;i++)
		cin>>c[i]>>a[i],c[i+n]=c[i],a[n+i]=a[i],dp1[i][i]=a[i],dp2[i][i]=a[i],dp1[i+n][i+n]=a[i],dp2[i+n][i+n]=a[i];
	int nn=2*n-1;
	for (int l=2;l<=n;l++)
		for (int i=1;i+l-1<=nn;i++)
		{
			int j=i+l-1;
			for (int k=i;k<j;k++) //决策点
			{
				if (c[k+1]=='t')
					dp1[i][j]=max(dp1[i][j],dp1[i][k]+dp1[k+1][j]),dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]);
				if (c[k+1]=='x')
					dp1[i][j]=max(dp1[i][j],max(dp1[i][k]*dp1[k+1][j],dp2[i][k]*dp2[k+1][j])),dp2[i][j]=min(dp2[i][j],min(dp1[i][k]*dp1[k+1][j],min(dp2[i][k]*dp2[k+1][j],min(dp1[i][k]*dp2[k+1][j],dp2[i][k]*dp1[k+1][j]))));
			}
		}
	int ans=-0x3f3f3f,cnt=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,dp1[i][i+n-1]);
	cout<<ans<<endl;
	for (int i=1;i<=n;i++)
		if (dp1[i][i+n-1]==ans)
			cout<<i<<' ';
	return 0;
}