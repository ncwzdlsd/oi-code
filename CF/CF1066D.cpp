#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn];

int main()
{
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=m,res=0;
    for(int i=n;i;i--)
    {
        if(res+a[i]<=k) res+=a[i];
        else cnt--,res=a[i];
        if(!cnt) cout<<(n-i),exit(0);  
    }
    cout<<n;
    return 0;
}