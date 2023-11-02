#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e4+5;
int a[maxn];

signed main()
{
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(n==1) cout<<a[1],exit(0);
    int ans=-INT_MAX;
    for(int i=1;i<n;i++) ans=max(ans,a[i]+a[i+1]);
    ans=max(ans,a[1]+a[n]);
    ans=max(ans,(int)ceil((double)sum/(n/2)));
    cout<<ans;
    return 0;
}