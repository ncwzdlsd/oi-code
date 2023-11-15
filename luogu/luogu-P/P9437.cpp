#include <bits/stdc++.h>
using namespace std;

const int mod=99824435,maxn=1e6+5;
int head[maxn],cnt;
struct node{int to,nxt;}e[maxn];

void add(int x,int y){e[++cnt]={y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
    
}

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,p;i<n;i++) cin>>p,add();
    return 0;
}