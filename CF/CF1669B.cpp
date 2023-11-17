#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int cnt[maxn],a[maxn];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    for(int i=1;i<=n;i++) if(cnt[i]>=3) return cout<<i<<'\n',void();
    cout<<"-1"<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}