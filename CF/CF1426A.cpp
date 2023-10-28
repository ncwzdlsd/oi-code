#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,x;cin>>n>>x;
    if(n==1||n==2) cout<<"1\n";
    else n-=2,cout<<(n%x?n/x+1:n/x)+1<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}