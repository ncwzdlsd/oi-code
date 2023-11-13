#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=105;
struct edge{int to,nxt;}e[maxn*maxn];
int head[maxn],cnt,deg[maxn],N;
queue<int> q;

void add(int x,int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}

void topo()
{
	for(int i=1;i<=N;i++)
		if(!deg[i]) q.push(i),cout<<i<<' ';
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt)
		{
			deg[e[i].to]--;
			if(!deg[e[i].to]) cout<<e[i].to<<' ',q.push(e[i].to);
		}
	}
}

signed main()
{
	cin>>N;
	for(int i=1,a;i<=N;i++) 
		while(cin>>a&&a) add(i,a),deg[a]++;
	topo();
	return 0;
}