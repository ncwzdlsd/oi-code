#include <bits/stdc++.h>
using namespace std;

const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int d[1005][1005],sx,sy,tx,ty,N;
char gg[1005][1005];
bool vis[1005][1005];

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++) cin>>gg[i][j];
	cin>>sx>>sy>>tx>>ty;
	// bfs();
	memset(vis,0,sizeof(vis));
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	d[sx][sy]=0;
	vis[sx][sy]=1;
	while(!q.empty())
	{
		pair<int,int> qwq=q.front();q.pop();
		int x=qwq.first,y=qwq.second;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx>=1&&nx<=N&&ny>=1&&ny<=N&&!vis[nx][ny]&&gg[nx][ny]=='0')
				vis[nx][ny]=1,q.push(make_pair(nx,ny)),d[nx][ny]=d[x][y]+1;
		}
	}
	cout<<d[tx][ty];
	return 0;
}