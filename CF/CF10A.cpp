#include <bits/stdc++.h>
using namespace std;

int l[105],r[105];

int main()
{
    int n,P1,P2,P3,T1,T2;cin>>n>>P1>>P2>>P3>>T1>>T2;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i],ans+=(r[i]-l[i])*P1;
    for(int i=1;i<=n;i++)
    {
        if(i==1) continue;
        if(l[i]-r[i-1]<=T1) ans+=(l[i]-r[i-1])*P1;
        else if(l[i]-r[i-1]>T1&&l[i]-r[i-1]<=T1+T2) ans+=T1*P1+(l[i]-r[i-1]-T1)*P2;
        else ans+=T1*P1+T2*P2+(l[i]-r[i-1]-T1-T2)*P3;
    }
    cout<<ans;
    return 0;
}