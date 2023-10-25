#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x,y;cin>>x>>y;
    if(y%x){cout<<"0 0"<<'\n';return;}
    else cout<<"1 "<<y/x<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}