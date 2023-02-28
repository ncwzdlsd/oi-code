#include <bits/stdc++.h>
using namespace std;

int to[500000],v[500000],father[500000],nxt[500000],cnt,head[500000],uu,vv,ans,M,N;

int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}

struct node
{
	int to,from,v;
}gg[500000];

bool cmp(node a,node b)
{
	return a.v<b.v;
}

int main()
{
	cin>>N>>M;
	int sum;
	for(int i=1;i<=N;i++) father[i]=i;
	for(int i=1;i<=M;i++) cin>>gg[i].from>>gg[i].to>>gg[i].v;
	sort(gg+1,gg+1+M,cmp);
	for(int i=1;i<=N;i++) father[i]=i;
	for(int i=1;i<=M&&cnt<N-1;i++)
	{
		int uu=find(gg[i].from),vv=find(gg[i].to);
		if(uu!=vv)
		{
			sum+=gg[i].v;
			father[uu]=vv;
			cnt++;
		}
	}
	if(cnt!=N-1)
		cout<<"orz";
	else
		cout<<sum;
	return 0;
}