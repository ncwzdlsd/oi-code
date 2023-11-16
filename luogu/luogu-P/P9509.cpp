#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1005;
int a[maxn],s[maxn];

void solve()
{
    int n;cin>>n;
    memset(s,0,sizeof s);
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i],s[i]=s[i-1]+a[i];
    if(sum%n) return cout<<"No\n",void();
    int v=sum/n,T=500;
    while(T--)
    {
        random_shuffle(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                if(s[j]-s[i-1]==(j-i+1)*v&&(j-i+1!=n)) return cout<<"Yes\n",void();
    }
    cout<<"No\n";
}

signed main()
{
    int q;cin>>q;
    while(q--) solve();
    return 0;
}