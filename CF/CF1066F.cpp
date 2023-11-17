#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;
int l[maxn],r[maxn],f[maxn][2];
struct node{int x,y,m;}p[maxn];

bool cmp(node a,node b)
{
    if(a.m!=b.m) return a.m<b.m;
    if(a.x!=b.x) return a.x<b.x;
    return a.y>b.y;
}

int dis(int i,int j){return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);}

signed main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y,p[i].m=max(p[i].x,p[i].y);
    sort(p+1,p+n+1,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i].m!=p[i-1].m) r[++cnt]=i;
        if(p[i].m!=p[i+1].m) l[cnt]=i;
    }
    for(int i=1;i<=cnt;i++)
        f[i][0]=min(f[i-1][0]+dis(l[i-1],r[i]),f[i-1][1]+dis(r[i-1],r[i]))+dis(l[i],r[i]),
        f[i][1]=min(f[i-1][0]+dis(l[i-1],l[i]),f[i-1][1]+dis(r[i-1],l[i]))+dis(l[i],r[i]);
    cout<<min(f[cnt][0],f[cnt][1]);
    return 0;
}