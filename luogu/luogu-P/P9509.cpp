#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1005;
int a[maxn];
set<int> s;

void solve()
{
    int n;cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(sum%n) return cout<<"No\n",void();
    int T=1000;sum/=n;
    for(int i=1;i<=n;i++) a[i]-=sum;
    while(T--)
    {
        random_shuffle(a+1,a+n+1);
        // for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
        int res=0;s.clear();
        for(int i=1;i<n;i++)
        {
        	res+=a[i];
        	if(!res||s.count(res)) return cout<<"Yes\n",void();
        	s.insert(res);
        }
    }
    cout<<"No\n";
}

signed main()
{
    int q;cin>>q;
    while(q--) solve();
    return 0;
}