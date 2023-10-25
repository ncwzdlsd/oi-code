#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;cin>>n;
    int ans1=0x3f3f3f,ans2=0x3f3f3f,ans=0x3f3f3f;
    for(int i=1;i<=n;i++)
    {
        int tme;string s;cin>>tme>>s;
        if(s[0]=='1') ans1=min(ans1,tme);
        if(s[1]=='1') ans2=min(ans2,tme);
        if(s[0]=='1'&&s[1]=='1') ans=min(ans,tme);
    }
    if((ans1==0x3f3f3f||ans2==0x3f3f3f)&&ans==0x3f3f3f) cout<<"-1"<<endl;
    else cout<<min(ans,ans1+ans2)<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}