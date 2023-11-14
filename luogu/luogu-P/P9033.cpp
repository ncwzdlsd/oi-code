#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int a[maxn];

int calc(int x)
{
    int cnt=0;
    while(x)
        x>>=1,cnt++; 
    return cnt;
}

void solve()
{
    int n,k,m;cin>>n>>k>>m;
    if(k<=m)
    {
        cout<<k<<' ';
        for(int i=1;i<n;i++) cout<<"0 ";
        cout<<'\n';
    }
    else 
    {
        if(n==1) return cout<<"-1\n",void();
        int p1=calc(k),p2=calc(m);
        if(p1>p2) return cout<<"-1\n",void();
        cout<<(1<<(p1-1))<<' '<<(k-(1<<(p1-1)));
        for(int i=3;i<=n;i++) cout<<" 0";
        cout<<"\n";
    }
}

int main()
{
    int T;cin>>T;
    while(T--) solve();
    return 0;
}