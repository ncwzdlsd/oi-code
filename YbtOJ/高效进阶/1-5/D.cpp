#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int head[maxn],nxt[maxn],to[maxn],cnt,w[maxn],diss[maxn];
char s[505][505];
bool vis[maxn];

void add(int x,int y,int z)
{
	to[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

struct node
{
	int id,dis;
	bool friend operator < (node a,node b)
	{
		return a.dis>b.dis;
	}
};
priority_queue<node> q;

void dij()
{
	memset(diss,0x3f,sizeof(diss));
	diss[1]=0;q.push(node{1,0});
	while(!q.empty())
	{
		node qwq=q.top();q.pop();
		int x=qwq.id;
		if(vis[x]) continue;
        vis[x]=1;
		for(int i=head[x];i;i=nxt[i])
			if(diss[to[i]]>diss[x]+w[i])
				diss[to[i]]=diss[x]+w[i],q.push(node{to[i],diss[to[i]]});
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int N,M;cin>>N>>M;
		for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin>>s[i][j];
		if((N+M)%2) cout<<"NO SOLUTION"<<endl;
		else
		{
			int qwq=N*(M+1)+M+1;
			for(int i=1;i<=qwq;i++)
				head[i]=0,nxt[i]=0,to[i]=0,w[i]=0,vis[i]=0,cnt=0;
			for(int i=1;i<=N;i++)
				for(int j=1;j<=M;j++)
				{
					int l1=(M+1)*(i-1)+j,l2=l1+M+1,r1=l1+1,r2=r1+M+1;
					if(s[i][j]=='\\') add(l1,r2,0),add(r2,l1,0),add(l2,r1,1),add(r1,l2,1);
					else add(l1,r2,1),add(r2,l1,1),add(l2,r1,0),add(r1,l2,0);
				}	
			dij();
			cout<<diss[qwq]<<endl;
		}
	}
	return 0;
}