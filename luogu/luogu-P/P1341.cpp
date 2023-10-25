#include <bits/stdc++.h>
using namespace std;

const int maxn=155;
bool G[maxn][maxn];
int n,f[maxn],deg[maxn];
char ch[5],stk[maxn<<2];

inline int find(int x)
{
    return x==f[x]?f[x]:f[x]=find(f[x]);
}
void qwq()
{
    scanf("%d",&n);
    for(int i=1;i<=150;i++)f[i]=i;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",ch+1);
            G[ch[1]][ch[2]]=G[ch[2]][ch[1]]=1;
            f[find(ch[1])]=find(ch[2]);
            ++deg[ch[1]],++deg[ch[2]];
        }
}
void dfs(int u)
{
    for(int i=1;i<=150;i++)
        if(G[u][i])
        {
            G[u][i]=G[i][u]=0;
            dfs(i);
        }
    stk[n--]=u;
}
void solve()
{
    int cnt=0,st=0;
    for(int i=1;i<=150;i++)if(f[i]==i&&deg[i])++cnt;
    if(cnt!=1){puts("No Solution");return;}
    cnt=0;
    for(int i=1;i<=150;i++)
        if(deg[i]&1)
        {
            ++cnt;
            if(!st)st=i;
        }
    if(!st){for(int i=1;i<=150;i++)if(deg[i]){st=i;break;}}
    if(cnt&&cnt!=2){puts("No Solution");exit(0);}
    dfs(st);
    puts(stk);
}
int main()
{
    qwq();
    solve();
    return 0;
}