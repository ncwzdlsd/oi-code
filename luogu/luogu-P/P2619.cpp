#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w,col;
}e[100005];
int f[50005],n,m,k;
bool cmp(edge a,edge b)
{
    if(a.w==b.w)return a.col<b.col;
    return a.w<b.w;
}
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
bool check(int now)
{
    for(int i=1;i<=m;i++)if(!e[i].col)e[i].w+=now;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    int sum=0,num=0;
    for(int i=1;i<=m;i++)
    {
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v)continue;
        f[v]=u;
        if(!e[i].col)num++;
        if((++sum)==n-1)break;
    }
    for(int i=1;i<=m;i++)if(!e[i].col)e[i].w-=now;
    return num>=k;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d",&e[i].u,&e[i].v,&e[i].w,&e[i].col);
        e[i].u++;e[i].v++;
    }
    int l=-0x7f,r=0x7f,res=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1,res=mid;
        else r=mid-1;
    }
    for(int i=1;i<=m;i++)if(!e[i].col)e[i].w+=res;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++)f[i]=i;
    int ans=0,sum=0;
    for(int i=1;i<=m;i++)
    {
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v)continue;
        f[v]=u;ans+=e[i].w;
        if((++sum)==n-1)break;
    }
    printf("%d",ans-k*res);
    return 0;
}