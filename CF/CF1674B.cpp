#include <bits/stdc++.h>
using namespace std;

void solve()
{
    char a,b;cin>>a>>b;
    int ans=(a-'a')*25;
    if(b>a) ans+=b-'a',cout<<ans<<'\n';
    else ans+=b-'a'+1,cout<<ans<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}