#include <bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
int a[maxn],f[maxn][2];

void solve()
{
    int n;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[1][1]=-1,f[1][0]=-1;
    int mx=0;
    for(int i=n;i;i--)
    {
        if(i+a[i]>n) f[i][1]=1;
        for(int i=1;i=1)
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}