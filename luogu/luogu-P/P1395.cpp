#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
struct edge{int to,nxt,w;}e[maxn*2];
int head[maxn],cnt,siz[maxn],ans,n;

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
       
}

signed main()
{
    cin>>n;
    for(int i=1,a,b;i<n;i++) cin>>a>>b,add(a,b),add(b,a);
    dfs(1,0);
    return 0;
}