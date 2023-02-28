#include <bits/stdc++.h>
using namespace std;

// 双BFS

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

int M,N,mx,my,gx,gy,zx[5],zy[5];
char s[805][805];
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool vm[805][805],vg[805][805];

bool check(int x,int y,int t)
{
	if(!(x>=1&&x<=N&&y>=1&&y<=M&&s[x][y]!='X')) return 0;//能不能走
	for(int i=1;i<=2;i++) if(abs(zx[i]-x)+abs(zy[i]-y)<=t*2) return 0;//僵尸
	return 1;
}

struct node
{
	int x,y;
};

void bfs()
{
	queue<node> q1,q2;
	q1.push(node{mx,my});q2.push(node{gx,gy});
	for(int t=1;!q1.empty()&&!q2.empty();t++)
	{
		for(int i=1;i<=3;i++)
			for(int k=q1.size();k;k--)
			{
				int x=q1.front().x,y=q1.front().y;q1.pop();
				if(!check(x,y,t)) continue;
				for(int j=0;j<4;j++)
				{
					int nx=x+dx[j],ny=y+dy[j];
					if(!check(nx,ny,t)||vm[nx][ny]) continue;
					if(vg[nx][ny]) {cout<<t<<endl;return;}
					vm[nx][ny]=1;
					q1.push(node{nx,ny});
				}
			}
		for(int k=q2.size();k;k--)
		{
			int x=q2.front().x,y=q2.front().y;q2.pop();
			if(!check(x,y,t)) continue;
			for(int j=0;j<4;j++)
			{
				int nx=x+dx[j],ny=y+dy[j];
				if(!check(nx,ny,t)||vg[nx][ny]) continue;
				if(vm[nx][ny]) {cout<<t<<endl;return;}
				vg[nx][ny]=1;
				q2.push(node{nx,ny});
			}
		}
	}
	cout<<-1<<endl;
	return;
}

int main()
{
	int T;T=read();
	while(T--)
	{
		N=read(),M=read();
		int cnt=0;
		for(int i=1;i<=N;i++)
			for(int j=1;j<=M;j++) 
			{
				cin>>s[i][j];
				if(s[i][j]=='M') mx=i,my=j;
				else if(s[i][j]=='G') gx=i,gy=j;
				else if(s[i][j]=='Z') zx[++cnt]=i,zy[cnt]=j;
				vm[i][j]=vg[i][j]=0;
			}
		bfs();
	}
	return 0;
}