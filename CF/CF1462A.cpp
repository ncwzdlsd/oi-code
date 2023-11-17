#include <bits/stdc++.h>
using namespace std;

const int maxn=305;
int b[maxn];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n/2;i++) cout<<b[i]<<' '<<b[n-i+1]<<' ';
    if(n%2) cout<<b[n/2+1];
    cout<<"\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}