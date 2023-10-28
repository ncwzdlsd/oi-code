#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll,bool> mp;

int main()
{
    int n;cin>>n;
    mp[0]=1;
    ll sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        sum+=x;
        if(mp[sum]) sum=x,ans++,mp.clear(),mp[0]=1;
        mp[sum]=1;
    }
    cout<<ans<<'\n';
    return 0;
}