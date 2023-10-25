#include<bits/stdc++.h>
using namespace std;

char a[110][110];
int v[110][110][4],dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
bool b[110][110][4];
struct node{
	int x,y,f;
};
deque<node> q;
int main()
{
	memset(v,0x3f,sizeof(v));
	int n,sx,sy,tx,ty;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='A')
				sx=i,sy=j;
			else if(a[i][j]=='B')
				a[i][j]='.',tx=i,ty=j;
		}
	for(int k=0;k<4;k++)
		q.push_back((node){sx,sy,k}),v[sx][sy][k]=0;
	while(!q.empty())
	{
		node x=q.front();
		q.pop_front();
		if(x.x==tx&&x.y==ty)
		{
			printf("%d\n",v[x.x][x.y][x.f]);
			return 0;
		}
		if(b[x.x][x.y][x.f])continue;
		b[x.x][x.y][x.f]=1;
		for(int i=0;i<4;i++)
		{
			int x1=x.x+dx[i],y1=x.y+dy[i];
			if(a[x1][y1]=='.'&&v[x.x][x.y][x.f]+(x.f!=i)<v[x1][y1][i])
			{
				v[x1][y1][i]=v[x.x][x.y][x.f]+(i!=x.f);
				if(i==x.f)q.push_front((node){x1,y1,i});
				else q.push_back((node){x1,y1,i});
			}
		}
	}
	puts("-1");
    return 0;
}