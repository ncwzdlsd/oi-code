#include <bits/stdc++.h>
using namespace std;

int a[105];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i;i--) cout<<a[i]<<' ';
    cout<<endl;
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}