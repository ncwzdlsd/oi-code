#include<bits/stdc++.h>
using namespace std;

int father[10005];

int find(int x)
{
	if(father[x]==x)
	{
		return x;
	}
	return father[x]=find(father[x]);
}

int c[10005],d[10005],f[10005];

int main()
{
	int n,m,w,x,y;cin>>n>>m>>w;
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i]>>d[i];
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		father[find(x)]=find(y);
	}

	for(int i=1;i<=n;i++)
		if(father[i]!=i)
			d[find(i)]+=d[i],d[i]=0,c[find(i)]+=c[i],c[i]=0;
	for(int i=1;i<=n;i++)//DP
	    for(int j=w;j>=c[i];j--)
	    	f[j]=max(f[j],f[j-c[i]]+d[i]);
	cout<<f[w];
	return 0;
}