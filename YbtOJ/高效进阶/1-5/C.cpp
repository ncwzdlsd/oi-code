#include <bits/stdc++.h>
using namespace std;

// 因为有技能使用次数限制，于是我们要把转移多加两维
// d[x][y][t1][t2]表示用t1次隐身t2次瞬移到达(x,y)的花费

const int dx[8]={-1,0,1,0,-1,1,1,-1},dy[8]={0,1,0,-1,1,1,-1,-1};
int mp[355][355],m,n,c1,c2,d,sx,sy,tx,ty;
char ch;
bool b[355][355],flag=0,vis[355][355][20][20];

struct node
{
	int x,y,t,t1,t2;
}a;
queue<node> q;

// ---OK---
void init(int x,int y,int v)
{
	// int nowx=x-v+1,y11=y,y22=y+1;//上半部分
	// for(int i=1;i<=v;i++)
	// {
		// if(nowx>0) mp[nowx][y11]++,mp[nowx][y22]--;//差分思路，左端点加1右端点减1
		// ++nowx,y11=max(y11-1,0),y22=min(y22+1,m+1);//防止越界
	// }
	// nowx=x+v-1,y11=y,y22=y+1;//下半部分
	// for(int i=1;i<v;i++)
	// {
		// if(nowx<=n) mp[nowx][y11]++,mp[nowx][y22]--;
		// --nowx,y11=max(y11-1,0),y22=min(y22+1,m+1);
	// }
	// cout<<mp[nowx][y22]<<"node"<<endl;
	for(int i=0;i<=v;i++)//从里向外扩展
	{
		mp[max(x-i,1)][max(y-(v-i),1)]++; 
		mp[max(x-i,1)][min(y+(v-i),m)+1]--;
		mp[min(x+i,n)][max(y-(v-i),1)]++;
		mp[min(x+i,n)][min(y+(v-i),m)+1]--;
	}
}
// -------

inline bool pd(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m; 
}

bool check(int t,int cnt1,int cnt2)
{
	if(t>a.t) return 0;
	else if(t<a.t) return 1;
	else if(cnt1+cnt2>a.t1+a.t2) return 0;
	else if(cnt1+cnt2<a.t1+a.t2) return 1;
	else return cnt1<a.t1;
}

signed main()
{
	cin>>n>>m>>c1>>c2>>d;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
		{
			cin>>ch;
			if(ch=='S') sx=i,sy=j;
			else if(ch=='T') tx=i,ty=j;
			else if(ch>='0'&&ch<='9')
			{
				b[i][j]=1;//是否有卫兵
				int x=0;
				while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
				if(x!=1) init(i,j,x-1);
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) mp[i][j]+=mp[i][j-1];
	// for(int i=1;i<=5;i++) cout<<mp[i][i]<<'q'<<endl;
	vis[sx][sy][0][0]=1;
	q.push(node{sx,sy,0,0,0});
	a.t=0x3f3f3f;
	while(!q.empty())
	{
		node now=q.front();q.pop();
		int t=now.t,cnt1=now.t1,x=now.x,y=now.y,cnt2=now.t2;
		if(t>a.t) continue;//最优性剪枝
		if(x==tx&&y==ty)
		{
			if(!flag) flag=1,a=now;
			else if(check(t,cnt1,cnt2)) a=now;
			// cout<<a.t<<"lala";
			check(t,cnt1,cnt2);
			continue;
		}
		for(int i=0;i<8;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||b[nx][ny]) continue;
			if(!mp[nx][ny]&&!vis[nx][ny][cnt1][cnt2])//不位移不隐身
				vis[nx][ny][cnt1][cnt2]=1,q.push(node{nx,ny,t+1,cnt1,cnt2});
			else if(mp[nx][ny]&&!b[nx][ny]&&cnt1<c1&&!vis[nx][ny][cnt1+1][cnt2])//不位移隐身
				vis[nx][ny][cnt1+1][cnt2]=1,q.push(node{nx,ny,t+1,cnt1+1,cnt2});
		}
		if(cnt2==c2) continue;
		for(int i=0;i<4;i++)
		{ 
			int nx=x+dx[i]*d,ny=y+dy[i]*d;
			if(nx<1||nx>n||ny<1||ny>m||b[nx][ny]) continue;
			if(!mp[nx][ny]&&!vis[nx][ny][cnt1][cnt2+1])//位移不隐身
				vis[nx][ny][cnt1][cnt2+1]=1,q.push(node{nx,ny,t+1,cnt1,cnt2+1});
			else if(mp[nx][ny]&&cnt1<c1&&!vis[nx][ny][cnt1+1][cnt2+1])//位移隐身
				vis[nx][ny][cnt1+1][cnt2+1]=1,q.push(node{nx,ny,t+1,cnt1+1,cnt2+1});
		}
		// cnt++;
	}
	if(flag) cout<<a.t<<' '<<a.t1<<' '<<a.t2;
	else cout<<-1;
	// cout<<cnt<<"node";
	// cout<<endl<<sx<<' '<<sy<<' '<<tx<<' '<<ty;
	// cout<<n<<m<<c1<<c2<<d;
	return 0;
}