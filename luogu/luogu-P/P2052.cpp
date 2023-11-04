#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
struct edge{int to,nxt,w;}e[maxn*2];
int head[maxn],cnt;

void add(int x,int y,int z){e[++cnt]={y,head[x],z},head[x]=cnt;}

void dfs(int x,int fa)
{
    
}

int main()
{
    int n;cin>>n;
    for(int i=1,a,b,c;i<n;i++) cin>>a>>b>>c,add(a,b,c),add(b,a,c);
    
    return 0;
}