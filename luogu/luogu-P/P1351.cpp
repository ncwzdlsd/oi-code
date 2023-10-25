#include <bits/stdc++.h>
using namespace std;

const int maxn=4e5+5,mod=10007;
int head[maxn],nxt[maxn],to[maxn],sum[maxn],ans,w[maxn],maxx,cnt;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x)
{
	int max1=0,max2=0,t1=0/*和的平方*/,t2=0/*平方和*/;
	for(int i=head[x];i;i=nxt[i])
	{
 		if(w[to[i]]>max1) max2=max1,max1=w[to[i]];
        else if(w[to[i]]>max2) max2=w[to[i]];
        t1=(t1+w[to[i]])%mod,t2=(t2+w[to[i]]*w[to[i]])%mod;	
    }
    t1=t1*t1%mod;
    ans=(ans+t1+mod-t2)%mod;
    if(maxx<max1*max2) maxx=max1*max2;
}

int main()
{
	int n;cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) dfs(i);
	cout<<maxx<<' '<<ans;
	return 0;
}