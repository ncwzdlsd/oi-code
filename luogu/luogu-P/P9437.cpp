#include <bits/stdc++.h>
using namespace std;

const int mod=998244353,maxn=1e6+5;
int head[maxn],cnt,pw[10];
struct node{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    for(int i=head[x];i;i=e[i].nxt)
    {
    	
    }
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,p;i<n;i++) cin>>p,add(p,i+1),add(i+1,p);
    pw[0]=1;
    for(int i=1;i<=9;i++) pw[i]=pw[i-1]*10;
    return 0;
}