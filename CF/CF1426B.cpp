#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,m;cin>>n>>m;
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        int a1,a2,a3,a4;
        cin>>a1>>a2>>a3>>a4;
        if(a2==a3) flag=1;
    }
    if(!flag||m%2) cout<<"NO\n";
    else cout<<"YES\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}