#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[505][505];
char a[505];

signed main()
{
	int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int len=2;len<=n;len++)
        for(int i=1,j=i+len-1;i+len-1<=n;i++,j++)
        {
            if(a[i]==a[j]) dp[i][j]=min(dp[i+1][j],dp[i][j-1]);
            else for(int k=i;k<j;k++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
        }
    cout<<dp[1][n]<<endl;
    return 0;
}