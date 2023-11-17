#include <bits/stdc++.h>
using namespace std;

int a[55];

void solve()
{
    int n;cin>>n;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2){if((a[i]%2)!=(a[1]%2)) flag=0;}
        else{if((a[i]%2)!=(a[2]%2)) flag=0;}
    }
    if(!flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}