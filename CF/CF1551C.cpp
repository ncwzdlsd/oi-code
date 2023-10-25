#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int cnt[5][maxn],dif[5][maxn];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) for(int j=0;j<5;j++) cnt[j][i]=0;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        for(int j=0;j<s.length();j++) cnt[s[j]-'a'][i]++;
        for(int j=0;j<5;j++) dif[j][i]=cnt[j][i]*2-s.length();
    }
    int ans=0;
    for(int i=0;i<5;i++)
    {
        sort(dif[i]+1,dif[i]+n+1);
        int now=0,tmp=0;
        int j=n;
        while(now+dif[i][j]>0&&j) now+=dif[i][j],tmp++,j--;
        ans=max(ans,tmp);
    }
    cout<<ans<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}