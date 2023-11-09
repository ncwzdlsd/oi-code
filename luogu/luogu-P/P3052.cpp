#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[1<<18],g[1<<18],w[20];

int main()
{
    int n,W;cin>>n>>W;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<=(1<<n);i++) f[i]=INT_MAX;
    f[0]=1,g[0]=W;
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
        {
            if(i&(1<<(j-1))) continue;
            if(g[i]>=w[j]&&f[i|(1<<(j-1))]>=f[i])
                f[i|(1<<(j-1))]=f[i],g[i|(1<<(j-1))]=max(g[i|(1<<(j-1))],g[i]-w[j]);
            else if(g[i]<w[j]&&f[i|(1<<(j-1))]>=f[i])
                f[i|(1<<(j-1))]=f[i]+1,g[i|(1<<(j-1))]=max(g[i|(1<<(j-1))],W-w[j]);
        }
    cout<<f[(1<<n)-1];
    return 0;
}