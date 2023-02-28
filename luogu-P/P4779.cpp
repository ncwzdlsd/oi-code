#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch == '-') f=-1 ; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48) ; ch=getchar();}
	return x*f;
}
const int M = 500010;
const int inf = 2147483647;
int n,m,s;
int cnt,head[M],vis[M];
long long dis[M];
struct egde
{
	int to,nxt,w;
}e[M];
typedef pair<int,int> pir;
priority_queue<pir,vector<pir>,greater<pir> >q;
void add(int u,int v,int w)
{
	e[++cnt].w = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
void dij(int s)
{
	for(register int i(1) ; i<=M-1 ; i=-~i) dis[i] = inf; //初始化为正无穷
	dis[s] = 0; 
	q.push(pir(0,s));
	while(!q.empty())
    {
		int f = q.top().first,u = q.top().second;
		q.pop();
		if(f!=dis[u]) continue; 
		for(register int i(head[u]) ; i ; i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v] > dis[u]+w)
            {
				dis[v] = dis[u]+w;
				q.push(pir(dis[v],v));
			}
		}
	}
}
int main()
{
	n=read();m=read();s=read();
	for(register int i(1) ; i<=m ; i=-~i)
    {
		int u,v,w;
		u=read();v=read();w=read();
		add(u,v,w);
	}
	dij(s);
	for(register int i(1) ; i<=n ; i=-~i) printf("%lld ",dis[i]);
	return 0;
}