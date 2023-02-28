#include <bits/stdc++.h>
using namespace std;

const int maxm=4005;
int N,M,fa[maxm];

int find(int x)
{
	if(x!=fa[x]) fa[x]=find(fa[x]);
	return fa[x];
}

struct node{int a,b,cost;}gg[maxm];

bool cmp(node x,node y)
{
	return x.cost<y.cost;
}

int main()
{
	cin>>N>>M;
	for(int i=1;i<=M;i++)
	{
		int cnt=0;double ans=0;
		cin>>gg[i].a>>gg[i].b>>gg[i].cost;
		sort(gg+1,gg+i+1,cmp);
		for(int j=1;j<=N;j++) fa[j]=j;
		for(int j=1;j<=i;j++)
		{
			int fu=find(gg[j].a),fv=find(gg[j].b);
			if(fu!=fv) fa[fu]=fv,cnt++,ans+=(gg[j].cost*1.0)/2.0;
			if(cnt==N-1) break;
		}
		if(cnt==N-1) printf("%0.1f\n",ans);
		else cout<<0<<endl;
	}
	return 0;
}