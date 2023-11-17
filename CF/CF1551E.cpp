#include <bits/stdc++.h>
using namespace std;

int a[2005],f[2005][2005];

void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
    for(int i=1;i<=n;i++) cin>>a[i],f[i][0]=f[i-1][0]+(a[i]==i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) f[i][j]=max(f[i-1][j-1],f[i-1][j]+(a[i]==i-j));
    for(int i=0;i<=n;i++) if(f[n][i]>=k) return cout<<i<<'\n',void();
    cout<<"-1\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}