#include <bits/stdc++.h>
using namespace std;
int n,ans,dp[35],x;
signed main()
{
    cin>>n;
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        int maxx=1;
        for(int j=0;j<=33;j++)
            if((1<<j)&x)maxx=max(maxx,dp[j]+1);
        for(int j=0;j<=33;j++)
            if((1<<j)&x) dp[j]=max(dp[j],maxx);
        ans=max(ans,maxx);
    }
    cout<<ans<<endl;
    return 0;
}
