#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
int a[maxn],cnt[35];

void solve()
{
    int ans=0;
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<=30;i++)
        for(int j=1;j<=n;j++) if(!((a[j]>>i)&1)) cnt[i]++;
    for(int i=30;i>=0;i--) 
        if(k>=cnt[i])
            k-=cnt[i],ans+=(1<<i);
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}