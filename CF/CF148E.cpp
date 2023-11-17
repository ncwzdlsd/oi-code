#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=105,maxm=1e4+5;
int g[maxn][maxn],f[maxn][maxm],s[maxn][maxn],num[maxn];

signed main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        for(int j=1,a;j<=num[i];j++) cin>>a,s[i][j]=s[i][j-1]+a;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=num[i];j++)
            for(int l=0;l<=j;l++) g[i][j]=max(g[i][j],s[i][l]+s[i][num[i]]-s[i][num[i]-(j-l)]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=min(j,num[i]);k++) f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k]);
    cout<<f[n][m];
    return 0;
}