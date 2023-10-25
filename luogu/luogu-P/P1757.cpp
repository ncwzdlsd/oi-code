#include <bits/stdc++.h>
using namespace std;

struct node
{
	int a,b,c;
}bb[10005];

node gg[1005][1005];//gg[i][j]存储小组i第j个物品的编号
int id[1005],f[10005],n,m,maxx;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>bb[i].a>>bb[i].b>>bb[i].c;
		id[bb[i].c]++;//第i组物品的物品总数
		gg[bb[i].c][id[bb[i].c]].b=bb[i].b;
		gg[bb[i].c][id[bb[i].c]].a=bb[i].a;
		maxx=max(bb[i].c,maxx);
	}
	for(int i=1;i<=maxx;i++)
		for(int j=n;j;j--)
			for(int k=1;k<=id[i];k++)
				if(j>=gg[i][k].a)
					f[j]=max(f[j],f[j-gg[i][k].a]+gg[i][k].b);
	cout<<f[n];
	return 0;
}