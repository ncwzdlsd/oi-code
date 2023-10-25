#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int dx[4]={0,1,-1,0},dy[4]={1,0,0,-1},a[maxn][maxn],sum,n,m;
bool vis[maxn][maxn];

void dfs(int x,int y)
{
    sum+=a[x][y];
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(vis[nx][ny]||nx<1||nx>n||ny<1||ny>m||!a[nx][ny]) continue;
        vis[nx][ny]=1,dfs(nx,ny);
    }
}

void solve()
{
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],vis[i][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j]||!a[i][j]) continue;
            sum=0,vis[i][j]=1;
            dfs(i,j),ans=max(ans,sum);
        }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}