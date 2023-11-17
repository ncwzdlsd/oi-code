#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    if(n==m) return cout<<"0\n",void();
    if((n&m)==m||(n|m)==m) cout<<"1\n";
    else cout<<"2\n";
}

signed main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}