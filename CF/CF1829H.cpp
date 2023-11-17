#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7,maxn=2e5+5;
int a[maxn],f[maxn][65];

int popcount(int x)
{
    int cnt=0;
    while(x) x&=(x-1),cnt++;
    return cnt;
}

void solve()
{
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) memset(f[i],0,sizeof f[i]),f[i][a[i]]=1;
    for(int i=1;i<=n;i++) 
        for(int j=0;j<64;j++) f[i][j]=(f[i-1][j]+f[i][j])%mod,f[i][j&a[i]]=(f[i-1][j]+f[i][j&a[i]])%mod;
    int ans=0;
    for(int i=0;i<64;i++) if(popcount(i)==k) ans=(ans+f[n][i])%mod;
    cout<<ans<<endl;
}

signed main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}