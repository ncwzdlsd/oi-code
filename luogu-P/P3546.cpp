#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5,base=131,mod=998244353;

int n;
int f[N];
ll h[N],qwq[N];
char s[N];

bool check(int lx,int rx,int ly,int ry)
{
    ll a=(h[rx]-h[lx-1]*qwq[rx-lx+1]%mod+mod)%mod,b=(h[ry]-h[ly-1]*qwq[ry-ly+1]%mod+mod)%mod;
    return a==b;
}
int main()
{
    cin>>n;
    scanf("%s",s+1);
    int ans=0;
    qwq[0]=1;
    for(int i=1;i<=n;++i) h[i]=(h[i-1]*base%mod+s[i]-'a')%mod;
    for(int i=1;i<=n;++i) qwq[i]=qwq[i-1]*base%mod;
    for(int i=(n>>1);i;--i)
    {
        f[i]=f[i+1]+2;
        while(f[i]+i>(n>>1)) --f[i];
        while(f[i]&&!check(i+1,i+f[i],n-i-f[i]+1,n-i)) --f[i];
    }
    for(int i=1;i<=(n>>1);++i) if(check(1,i,n-i+1,n)) ans=max(ans,f[i]+i);
    cout<<ans;
    return 0;
}