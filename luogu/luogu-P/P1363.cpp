#include<bits/stdc++.h>
using namespace std;
int book[1505][1505][5],a[1505][1505],n,m,startx,starty,ans;
char q;
int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
 
void dfs(int x,int y,int tx,int ty)
{
    if(ans) return;
    if(book[x][y][0] && (book[x][y][1] != tx || book[x][y][2]!= ty))
    {
        ans = 1;
        return;
    }
    book[x][y][1] = tx;
    book[x][y][2] = ty;
    book[x][y][0] = 1;
    for(int k = 0;k <= 3;k++)
    {
        int xx = (x + step[k][0] + n) % n;
        int yy = (y + step[k][1] + m) % m;
        int txx = tx + step[k][0];
        int tyy = ty + step[k][1];
        if(!a[xx][yy])
            if(!book[xx][yy][0] || book[xx][yy][1] != txx || book[xx][yy][2] != tyy)
                dfs(xx,yy,txx,tyy);
	}
}
 
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ans = 0;
        memset(a,0,sizeof(a));
        memset(book,0,sizeof(book));
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cin >> q;
                if(q == '#') a[i][j] = 1;
                if(q == 'S')
                    startx = i,starty = j;
            }
        }
        dfs(startx,starty,startx,starty);
        if(ans) puts("Yes");
        else puts("No");
    }
    return 0;
}