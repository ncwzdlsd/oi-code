#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int b[maxn];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    int x=0,y=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==1) y++;
        else x+=y,y=0;
        if(!x) ans=max(ans,y+x);
        else ans=max(ans,y+x/2+1);
    }
    cout<<ans<<endl;
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}