#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[30][30];

void solve()
{
    int n;cin>>n;
    memset(cnt,0,sizeof cnt);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        char a,b;cin>>a>>b;
        cnt[a-'a'][b-'a']++;
        for(int j=0;j<11;j++)
        {
            if(cnt[a-'a'][j]&&j!=b-'a') ans+=cnt[a-'a'][j];
            if(cnt[j][b-'a']&&j!=a-'a') ans+=cnt[j][b-'a'];
        }
    }
    cout<<ans<<'\n';
}

signed main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}