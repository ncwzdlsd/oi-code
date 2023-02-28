#include <bits/stdc++.h>
using namespace std;

int mx[100005],to[100005],head[100005]nxt[100005],;

void add(int x,int y)
{
    int cnt=0;
    cnt++,to[cnt]=head[x];
    head[x]=cnt;
}

void dfs(int x)
{
    if(mx[x]) return mx[x];
    mx=[x];
    for(int i=1;i<=head[x];i=nxt[i])
        dfs(to[i]),mx[x]=max(mx[x],mx[to[i]]);
}

int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>x>>y,add(x,y);
    for(int i=1;i<=n;i++)
        dfs(i);
    for(int i=1;i<=n;i++)
        cout<<mx[i]<<' ';
}