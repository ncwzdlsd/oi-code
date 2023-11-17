#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve()
{
    int w;cin>>w;
    int now=3,ans=3;
    while(now<w)
        ans++,now*=2;
    cout<<ans<<'\n';
}

signed main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}