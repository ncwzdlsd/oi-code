#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
int head[maxn],cnt,w[maxn],v[maxn],W,N,pool[maxn];
struct edge{int to,nxt;}e[maxn*2];

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void dfs(int x,int fa)
{
	
}

int main()
{
	cin>>N>>W;
	int (&f)[N+1][W+1]=decltype(f)(pool);
	for(int i=1,d;i<=N;i++)
	{
		cin>>d;
		if(!d) add(0,d);
		else add(d,i);
	}
	for(int i=1;i<=N;i++) cin>>w[i];
	for(int i=1;i<=N;i++) cin>>v[i];
	dfs(0,0);
	cout<<f[0][W+1];
	return 0;
}