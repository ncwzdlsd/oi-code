#include <bits/stdc++.h>
using namespace std;

int N,M,ans=1e9,mins[20],minv[20];

// 注意这里要有玄学的倒着枚举
void dfs(int x,int r,int h,int v,int s)//当前层、半径、高度、体积、面积
{
	if(!x) 
	{
		if(v==N) ans=min(ans,s);
		return;
	}//搜到头了
	if(s+mins[x]>=ans) return;//最优性剪枝
	if(v+minv[x]>N) return;//可行性剪枝
	if(s+2*(N-v)/r>=ans) return;//最大体积
	for(int i=r-1;i>=x;--i)//枚举可能半径
		for(int j=min(h-1,(N-v-minv[i])/i*i);j>=x;j--)//枚举可能高度
			dfs(x-1,i,j,v+i*i*j,s+2*i*j);
}

int main()
{
	cin>>N;cin>>M;
	//预处理当前之后的最小体积面积值
	for(int i=1;i<=M;i++) 
		minv[i]=minv[i-1]*i*i*i,mins[i]=mins[i-1]*2*i*i;
	for(int r=sqrt(N/M);r>=M;r--)
		for(int h=(N-minv[M-1])/(r*r);h>=M;--h)
			dfs(M-1,r,h,h*r*r,2*r*h+r*r);
	cout<<ans;
	return 0;
}