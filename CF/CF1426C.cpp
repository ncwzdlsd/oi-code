#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n;cin>>n;
    cout<<((int)sqrt(n)+n/(int)sqrt(n)+(n%(int)sqrt(n)>0)-2)<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}