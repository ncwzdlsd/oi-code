#include <bits/stdc++.h>
using namespace std;

const int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
// 注意题中说的是“顶点相邻”
int w[1005][1005],n,ans1,ans2,cnt;
bool vis[1005][1005];

void bfs(int sx,int sy)
{
	queue<pair<int,int> >q;
	q.push(make_pair(sx,sy));
	vis[sx][sy]=1;
	int h=w[sx][sy];
	bool f1=0,f2=0;//是否是山峰/山谷
	while(!q.empty())
	{
		pair<int,int> qwq=q.front();q.pop();
		int x=qwq.first,y=qwq.second;
		for(int i=0;i<8;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>n) continue;
			if(w[nx][ny]!=h)//新点不与连通块等高
			{
				if(w[nx][ny]<h) f1=1;
				if(w[nx][ny]>h) f2=1;
			}
			else if(!vis[nx][ny]) {vis[nx][ny]=1,q.push(make_pair(nx,ny));cnt++;}
		}
	}
	if(!f1&&!f2) ans1++,ans2++;
	if(f1&&!f2) ans1++;
	if(!f1&&f2) ans2++;
	if(cnt==n*n) ans1++,ans2++;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>w[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(!vis[i][j]) bfs(i,j);
	cout<<ans1<<' '<<ans2;
	return 0;
}