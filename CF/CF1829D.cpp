#include <bits/stdc++.h>
using namespace std;

int n,m;

bool dfs(int x)
{
    if(x==m) return 1;
    if(x<m) return 0;
    if(x%3) return 0;
    return dfs(x/3)|dfs(x/3*2);    
}

void solve()
{
    cin>>n>>m;
    if(dfs(n)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}