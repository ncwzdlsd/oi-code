#include<bits/stdc++.h>
using namespace std;

const int maxn=100005*2;
int head[maxn],to[maxn],nxt[maxn],cnt,dp[maxn][25][2],m[maxn],k,father[maxn]; 
//f[i][j][0]表示只考虑节点i的子树，与节点i距离小于等于j的节点权值之和（包括当前节点）
//f[i][j][1]表示对于该点父节点，与该点父节点距离小于等于j-1的节点权值之和（忽略当前子节点）（符合条件的）

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

void dfs(int x,int fa)
{
	father[x]=fa;
	for(int i=1;i<=k;i++)
		dp[x][i][0]=dp[x][0][0];
	for(int i=head[x];i;i=nxt[i])
    {
        if(to[i]==fa) continue;
        dfs(to[i],x);
		for(int j=1;j<=k;j++)
			dp[x][j][0]+=dp[to[i]][j-1][0];
    }
    for(int i=head[x];i;i=nxt[i])
    {
    	if(to[i]==fa) continue;
    	dp[to[i]][1][1]=dp[x][0][0];
    	for(int j=2;j<=k;j++)
    		dp[to[i]][j][1]=dp[x][j-1][0]-dp[to[i]][j-2][0];
    		// 考虑to[i]的父节点即x，因为有多的点权所以要用到容斥原理处理
    		// 举个栗子，对于一个二叉树（中序遍历）7-4-2-1-3-5-8-9-6，我们要求距离节点2距离为3的点，我们找到2的父亲1，找与1距离为2的点，发现有4 5 6不符合(与子树同层的点)
    		// 这些点的特征就是距离节点2的距离为k-2
    }
}

int main()
{
    int n,u,v;cin>>n>>k;
    for(int i=1;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
    for(int i=1;i<=n;i++) cin>>dp[i][0][0];
    dfs(1,0);
    for(int i=1;i<=n;i++) m[i]=dp[i][k][1];
	for(int i=1;i<=n;i++)
	{
		m[i]=dp[i][k][0];int id=i;
		for(int j=1;j<=n;j++)
		{
			m[i]+=dp[id][k-j+1][1];
			u=father[u];
			if(!u) break;
		}
	}
	for(int i=1;i<=n;i++) cout<<m[i]<<endl;
    return 0;
}