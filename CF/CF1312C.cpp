#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnt[105];

void solve()
{
    int n,k;cin>>n>>k;
    memset(cnt,0,sizeof cnt);
    int mxlen=0,len;
    for(int i=1;i<=n;i++)
    {
        ll a;cin>>a,len=1;
        while(a) cnt[len]+=a%k,a/=k,mxlen=max(mxlen,++len);
    }    
    for(int i=1;i<=mxlen;i++) if(cnt[i]>1){cout<<"NO"<<endl;return;}
    cout<<"YES"<<endl;
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}