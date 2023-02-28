#include <bits/stdc++.h>
using namespace std;

const int maxn=30;
int n,m,cnt,gg[maxn][maxn],maxl,f[30]/*序列长度*/,q[30]/*数组模拟队列*/,ru[100]/*入度*/;

void topo(int x)//以x为起点的拓补序列
{
	for(int i=1;i<=n;i++)
	{
		if(gg[x][i]==1&&ru[i])//x指向i的路，i入度不为0
		{
			ru[i]--;
			f[i]=max(f[i],f[x]+1);//更新序列长度
			maxl=max(maxl,f[i]);//更新序列最大长度
			if(ru[i]==0) q[++cnt]=i;
		}
	}
}

int main()
{
	string s;bool flag;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		int x=s[0]-'A'+1,y=s[2]-'A'+1;
		gg[x][y]=1;
		if(x==y) printf("Inconsistency found after %d relations.",i),exit(0);
		memset(ru,0,sizeof(ru));
		for(int j=1;j<=n;j++)
		{
			f[j]=1;
			for(int k=1;k<=n;k++)
				ru[k]+=gg[j][k];
		}
		maxl=0,cnt=0;
		for(int j=1;j<=n;j++)
			if(!ru[j]) q[++cnt]=j;//入度为0，入队
		int rr=0;
		while(rr<cnt)
			rr++,topo(q[rr]);
		if(maxl==n)
		{
			printf("Sorted sequence determined after %d relations: ",i);
	    	for (int j=1;j<=n;j++) printf("%c",q[j]+64);
	    	cout<<".",exit(0);
		}
		for(int j=1;j<=n;j++) if(ru[j]) flag=true;
		if(flag) printf("Inconsistency found after %d relations.",i),exit(0);
	}
	printf("Sorted sequence cannot be determined.");
	return 0;
}