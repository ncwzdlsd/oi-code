#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    ll N,A,B,X,Y,Z;
    cin>>N>>A>>B>>X>>Y>>Z;
    Y=min(Y,A*X),Z=min(Z,B*X);
    if(A*Z<B*Y) swap(A,B),swap(Y,Z);
    ll ans=LLONG_MAX,tmp=0;
    if(N/A<A-1) for(int i=0;i<=(N/A);++i) tmp=N-i*A,ans=min(ans,i*Y+tmp/B*Z+tmp%B*X);
    else for(int i=0;i<=A-1;++i)
    {
        tmp=N-i*B;
        if(tmp>=0) ans=min(ans,i*Z+tmp/A*Y+tmp%A*X);
    }
    cout<<ans<<endl;
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}