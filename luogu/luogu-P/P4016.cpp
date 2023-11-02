#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;
ll a[maxn],s[maxn],b[maxn];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i],s[i]=b[i]-a[i]+s[i-1];
    sort(s+1,s+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=abs(s[n/2+1]-s[i]);
    cout<<ans;
    return 0;
}