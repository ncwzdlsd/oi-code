#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,b[N],f[N],d[N],gg[N],ans,u,v,w;
bggggl cmp(int x,int y){return d[x]>d[y];}
int main()
{
	cin>>n;
	b[1]=1,gg[1]=gg[0]=N;
	for(int i=2,n) cin>>f[i],d[i]=d[f[i]]+1,b[i]=i,gg[i]=N;
	sort(b+1,b+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		v=b[i],w=f[v],u=f[f[v]];
		gg[v]=min(gg[v],min(gg[w]+1,gg[u]+2));
		if(gg[v]>2)
			gg[u]=0,ans++,gg[f[u]]=min(gg[f[u]],1),gg[f[f[u]]]=min(gg[f[f[u]]],2);
	}
	cout<<ans;
	return 0;
}