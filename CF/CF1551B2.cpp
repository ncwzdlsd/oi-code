#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int cnt[maxn],ans[maxn],ct[maxn];
struct node{int id,v;}a[maxn],b[maxn];

bool cmp(node a,node b)
{return a.v<b.v;}

void solve()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<=n;i++) cnt[i]=0,ans[i]=0,ct[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i].v,cnt[a[i].v]++,a[i].id=i;
    int tmp=0;
    for(int i=1;i<=n;i++) 
    {
        if(cnt[a[i].v]<k) b[++tmp]=a[i];
        else if(cnt[a[i].v]>=k&&ct[a[i].v]<k) ct[a[i].v]++,ans[a[i].id]=ct[a[i].v];
    }
    sort(b+1,b+tmp+1,cmp);
    int tp=1,tot=tmp/k*k;
    for(int i=1;i<=tot;i++)
    {
        ans[b[i].id]=tp,tp++;
        if(tp>k) tp=1;
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
}

int main()
{
    int t;cin>>t;
    while(t--) solve();
    return 0;
}