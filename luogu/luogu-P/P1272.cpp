#include <bits/stdc++.h>
using namespace std;

// 三维数组朴素思路f[i][j][k]表示考虑节点i的前k棵子树得到大小为j的子树需要的最小删除数
// f[i][j][k]=min(f[i][k-1][j]+1,f[i][k-1][j-son]+f[son][k_son][s_son])
// 前面表示不选第k棵子树，那么删除连接边再+1；后面表示选了这棵子树

// f[i][j]表示在节点i分离大小为j的子树需要的删除边的数量
const int maxn=305;
int head[maxn],to[maxn],ans,nxt[maxn],cnt,f[maxn][maxn],sum[maxn];

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa)
{
	sum[x]=1;//sum[x]表示x的子树的节点数
	// 我们要考虑在 DFS 的过程中维护每个结点的子节点数量
	for(int i=head[x];i;i=nxt[i])
	{
		if(to[i]==fa) continue;
		dfs(to[i],x);
		sum[x]+=sum[to[i]];//sum表示子树大小
		for(int j=sum[x];j;j--)
		{
			f[x][j]+=1;//想要取出这棵子树，代价要加1
			for(int k=0;k<=min(j-1,sum[to[i]]);k++)//j-1是为了强制要求给当前子树分配空间
				f[x][j]=min(f[x][j],f[x][j-k]+f[to[i]][k]);
		}
	}
}

int main()
{
	int N,P;cin>>N>>P;
	for(int i=1;i<N;i++) {int I,J;cin>>I>>J,add(I,J),add(J,I);}
	memset(f,0x3f,sizeof(f));
	dfs(1,0);
	ans=f[1][P];
	for(int i=2;i<=N;i++) ans=min(ans,f[i][P]+1);//加上与父节点割开的那条边
	cout<<ans;
	return 0;
}