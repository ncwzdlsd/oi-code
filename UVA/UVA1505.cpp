#include <bits/stdc++.h>
using namespace std;
int a[10][10],n,l[] = {-1,1,0,0},r[] = {0,0,-1,1},v[10],vis[10][10],lim;
void dfs(int now, int x, int y)
{
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++i)
    {
        int xx = x + l[i], yy = y + r[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= n || vis[xx][yy] == 1) continue;
        vis[xx][yy] = 2;
        if(a[xx][yy] == now) dfs(now,xx,yy);
    }
} 
int qwq(int now)
{
    int p = 0;
    for(int i = 0;i < n;++i)
        for(int j = 0;j < n;++j)
            if(a[i][j] == now && vis[i][j] == 2)
                dfs(now,i,j),++p;
    return p;
}
int IDA(int now, int dep)
{
    v[0] = v[1] = v[2] = v[3] = v[4] = v[5] = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(vis[i][j] != 1)
                v[a[i][j]] = 1;
    int f = v[0] + v[1] + v[2] + v[3] + v[4] + v[5];
    if(!f) return 1;
    if(dep + f > lim) return 0;
    int tmp[10][10];
    memcpy(tmp,vis,sizeof(vis));
    for(int k = 0; k < 6; ++k)
    {
        if(k == now) continue;
        if(qwq(k) && IDA(k,dep + 1)) return 1;
        memcpy(vis,tmp,sizeof(vis));
    }
    return 0;
}
int main()
{
    while(cin>>n&&n)
    {
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j) cin>>a[i][j];
        memset(vis,0,sizeof(vis));
        dfs(a[0][0],0,0);
        for(lim = 0;;++lim)
            if(IDA(a[0][0], 0))
            {
                cout<<lim<<endl;break;
            }
    }
    return 0;
}