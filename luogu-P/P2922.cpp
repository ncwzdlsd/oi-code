#include <bits/stdc++.h>
using namespace std;

int sum[500005],endd[500005],bi,cj,tot=1,p[500005][3]/*指针记录节点i的字符j指向的根节点*/;
bool t[50005];

void insert(bool t[])
{
	int u=1;
	for(int i=1;i<=bi;i++)
	{
		int c=t[i];
		if(p[u][c]==-1) p[u][c]=++tot;
		u=p[u][c];
		sum[u]++;
	}
	endd[u]++;
}

int find(bool t[])
{
	int u=1,res=0;
	for(int i=1;i<=cj;i++)
	{
		int c=t[i];
		if(p[u][c]==-1) return res;
		u=p[u][c];
		res+=endd[u];
	}
	return res-endd[u]+sum[u];
}

int main()
{
	int M,N;cin>>M>>N;
	memset(p,-1,sizeof(p));
	for(int i=1;i<=M;i++)
	{
		cin>>bi;
		for(int j=1;j<=bi;j++) cin>>t[j];
		insert(t);
	}
	for(int i=1;i<=N;i++)
	{
		cin>>cj;
		for(int j=1;j<=cj;j++) cin>>t[j];
		cout<<find(t)<<endl;
	}
	return 0;
}