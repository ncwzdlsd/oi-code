#include<iostream>
#include<queue>
using namespace std;
int n,x1,y1,x2,y2;
char a[1007][1007];
int vis[1007][1007];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct node
{
	int a,b,dis;
	node(int x=0,int y=0,int dis1=0)
    {
		a=x;
        b=y;
        dis=dis1;
	}
};
queue<node> que;
void bfs(int x,int y)
{
	que.push(node(x,y,0));
    vis[x][y]=1;
	while(!que.empty())
    {
		node t=que.front();
	    que.pop();
		if(t.a==x2 && t.b==y2)
        {
            cout<<t.dis;
            return;
        }
	    for(int i=0;i<4;i++)
        {
            int tx=t.a+dx[i];
	    	int ty=t.b+dy[i];
	        if(tx<=0 || tx>n || ty<=0 || ty>n || a[tx][ty]=='1' || vis[tx][ty])
                continue;
            que.push(node(tx,ty,t.dis+1));
            vis[tx][ty]=1;
		}
	}
    return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	cin>>x1>>y1>>x2>>y2;
	bfs(x1,y1);
	return 0;
}