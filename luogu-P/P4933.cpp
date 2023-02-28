#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,maxn=1005;
int h[maxn],n,ans,dp[maxn][maxn];

int main()
{
	cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i],dp[0][i]=1;
    ans+=n;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            dp[j][i]=dp[0][j];
            for(int k=1;k<j;k++) 
            	if(h[j]*2==h[k]+h[i]) 
            		dp[j][i]=(dp[j][i]+dp[k][j])%mod;
            ans=(ans+dp[j][i])%mod;
        }
	cout<<ans;
    return 0;
}