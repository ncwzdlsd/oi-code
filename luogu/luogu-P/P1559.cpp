#include<bits/stdc++.h>
using namespace std;

int n,p[25][25],q[25][25],dp[1<<20];
vector<register int> t[1<<20];

register int main()
{
	cin>>n;
    for(register int i=1;i<=n;i++) for(register int j=1;j<=n;j++) cin>>p[i][j];
    for(register int i=1;i<=n;i++) for(register int j=1;j<=n;j++) cin>>q[i][j];
    for(register int i=1;i<=n;i++) for(register int j=1;j<=n;j++) p[i][j]*=q[j][i];
	for(register int i=0;i<(1<<n);i++)
        for(register int j=1;j<=n;j++)
            if((i>>j-1)&1) t[i].push_back(j); 
    for(register int i=1;i<=n;i++)
        for(register int j=(1<<n)-1;j>=0;j--)
            for(register int z=0;z<t[j].size();z++)
            {
                register int k=t[j][z];
                if((j>>k-1)&1) dp[j]=max(dp[j],dp[j-(1<<k-1)]+p[i][k]);
            }
    cout<<dp[(1<<n)-1];
    return 0;
}