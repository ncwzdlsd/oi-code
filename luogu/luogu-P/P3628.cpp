#include<bits/stdc++.h>
using namespace std;

const int maxn=1000005;
int dp[maxn],sum[maxn],q[maxn],n,a,b,c;

double getk(int x,int y)
{
    return 1.0*(dp[x]-dp[y]+a*sum[x]*sum[x]-a*sum[y]*sum[y]+b*sum[y]-b*sum[x])/(2*a*(sum[x]-sum[y]));
}

int main()
{
	cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++)
        cin>>sum[i],sum[i]=sum[i-1]+sum[i];
    int ll=0,rr=0;
    for(int i=1;i<=n;i++)
    {
        while(ll<rr&&getk(q[ll],q[ll+1])<=sum[i]) ll++;
        dp[i]=dp[q[ll]]+a*(sum[i]-sum[q[ll]])*(sum[i]-sum[q[ll]])+b*(sum[i]-sum[q[ll]])+c;
        while(ll<rr&&getk(q[rr-1],q[rr])>=getk(q[rr],i)) rr--;
        q[++rr]=i;
    }
    cout<<dp[n];
    return 0;
}