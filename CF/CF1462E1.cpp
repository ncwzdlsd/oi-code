#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7,maxn=2e5+5;
int fac[maxn],inv[maxn],a[maxn];

int quickpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=a*a%mod,b>>=1;
    }
    return res;
}

void init()
{
    fac[0]=1;
    for(int i=1;i<=2e5;i++) fac[i]=fac[i-1]*i%mod;
    inv[200000]=quickpow(fac[200000],mod-2);
    for(int i=199999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}

void solve()
{
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int j=1;
    for(int i=1;i<=n;i++)
    {
        while(a[j+1]-a[i]<=2&&j+1<=n) j++;
        if(j-i>=2) ans+=(j-i)*(j-i-1)/2;
    }
    cout<<ans<<"\n";
}

signed main()
{
    int t;cin>>t;
    init();
    while(t--) solve();
    return 0;
}