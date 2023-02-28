#include <bits/stdc++.h>
using namespace std;

// f[i][j][fj]表示前i轮变换j次手势最后一次出fj的最多胜利次数
// 对于fj，0代表石头H，1代表剪刀R，2代表布P
// 分类讨论，第i轮分别出0、1、2
// 用前缀和数组s1、s2、s3分别表示1~i轮出0、1、2胜利的次数
// f[i][j][0]=max(f[i][j][0],max(f[k][j-1][1],f[k][j-1][2])+s1[i]-s1[k])
// f[i][j][1]=max(f[i][j][1],max(f[k][j-1][0],f[k][j-1][2])+s2[i]-s2[k])
// f[i][j][2]=max(f[i][j][2],max(f[k][j-1][0],f[k][j-1][1])+s3[i]-s3[k])
// 考虑化DP为记忆化搜索，用DFS之后的状态值作为答案，不依靠外部变量（即在外部且随着DFS进行值改变的变量）

int N,K,f[100005][25][3],qwq[100005];

int dfs(int id,int kk,int now)
// id表示当前次选择了0/1/2，kk为使用的机会次数，now表示已经进行了now轮
// 由于是统计胜利次数，所以只需要考虑有可能胜利的状态
{
	if(now>N||kk>K) return 0;
	if(f[id][kk][now]) return f[id][kk][now];
	if(kk==K)
	{
		// 如果赢了，+1
		if(id==1&&qwq[now]==2) f[now][kk][id]=dfs(1,kk,now+1)+1;
		else if(id==2&&qwq[now]==3) f[now][kk][id]=dfs(2,kk,now+1)+1;
		else if(id==3&&qwq[now]==1) f[now][kk][id]=dfs(3,kk,now+1)+1;
		// 如果输了，不+1
		if(id==1&&qwq[now]==2) f[now][kk][id]=dfs(1,kk,now+1);
		else if(id==2&&qwq[now]==3) f[now][kk][id]=dfs(2,kk,now+1);
		else if(id==3&&qwq[now]==1) f[now][kk][id]=dfs(3,kk,now+1);
	}
}

char qq;

int main()
{
	int N,K;cin>>N>>K;
	for(int i=1;i<=N;i++)
	{
		cin>>qq;
		if(qq=='H') f[i]=0;
		if(qq=='R') f[i]=1;
		if(qq=='P') f[i]=2;
	}
	int ans;
	return 0;
}