#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
const int maxm=2e4+5,maxn=105,maxs=105;
int s,n,m;
int val[maxn][maxm],dp[maxm],b[maxn][maxs],maxx[maxn];
int main()
{
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++)
        for(int j=1;j<=n;j++)
            cin>>b[j][i];
    for(int i=1;i<=n;i++)
        sort(b[i]+1,b[i]+1+s);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            for(int k=1;k<=s;k++)
                if(j>2*b[i][k]) dp[j]=max(dp[j],dp[j-2*b[i][k]-1]+k*i);
    cout<<dp[m]<<endl;
    return 0;
}