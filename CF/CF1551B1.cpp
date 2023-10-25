#include <bits/stdc++.h>
using namespace std;

int cnt[30];

void solve()
{
    string s;cin>>s;
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<s.length();i++) cnt[s[i]-'a']++;
    int cnt1=0,cnt2=0;
    for(int i=0;i<26;i++) 
    {
        if(cnt[i]==1) cnt1++;
        else if(cnt[i]>1) cnt2++;
    }
    cout<<(cnt1/2+cnt2)<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}