#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=3005;
int a[maxn];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int res=0,acnt=0,sum=0,ans=0x3f3f3f;
    for(int i=1;i<=n;i++)
    {
        if(i>1) ++acnt;
        res=acnt,sum+=a[i];
        int tmp=0;
        bool flag=1;
        for(int j=i+1;j<=n;j++)
        {
            if(tmp) ++res;
            tmp+=a[j];
            if(tmp==sum) tmp=0;
            else if(tmp>sum) {flag=0,tmp=0;break;}
        }
        if(flag&&(!tmp)) ans=min(ans,res); 
    }
    cout<<ans<<"\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}