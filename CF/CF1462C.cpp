#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[10];

void solve()
{
    int x;cin>>x;
    if(x>45) return cout<<"-1\n",void();
    int tot=0;
    for(int i=9;i>=0;i--)
    {
        if(i>x) continue;
        x-=i,a[++tot]=i;
        if(!x) break;
    }
    for(int i=tot;i;i--) cout<<a[i];
    cout<<"\n";
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}