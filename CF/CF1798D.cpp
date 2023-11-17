#include <bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;
int a[maxn],b[maxn];

void solve()
{
    int n;cin>>n;
    bool flag=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        if(a[i]) flag=1;
    }
    if(!flag) return cout<<"No"<<endl,void();
    int sum=0;
    sort(a+1,a+n+1);
    int l=1,r=n,cnt=0;
    while(l<=r)
    {
        if(sum<=0) sum+=a[r],b[++cnt]=a[r],r--;
        else sum+=a[l],b[++cnt]=a[l],l++;
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}