#include <bits/stdc++.h>
using namespace std;

const int maxn=2005;
int gg[maxn][maxn],leftt[maxn][maxn]/*万能头里有left函数*/,rightt[maxn][maxn],height[maxn][maxn],N,M,ans1,ans2;

int main()
{
	cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			cin>>gg[i][j];
			leftt[i][j]=rightt[i][j]=j;//建立悬线
			height[i][j]=1;//初始化，如果上下两个点相同也可以有一条长度为1的悬线
		}
	for(int i=1;i<=N;i++)
		for(int j=2;j<=M;j++)//注意从2开始
			if(gg[i][j]!=gg[i][j-1])
				leftt[i][j]=leftt[i][j-1];//预处理左边界
	for(int i=1;i<=N;i++)
		for(int j=M-1;j>0;j--)//注意从M-1开始
			if(gg[i][j]!=gg[i][j+1])
				rightt[i][j]=rightt[i][j+1];//预处理右边界，注意要从终边开始减
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
		{
			if(i>1&&gg[i][j]!=gg[i-1][j])
			{
				leftt[i][j]=max(leftt[i][j],leftt[i-1][j]);
				rightt[i][j]=min(rightt[i][j],rightt[i-1][j]);
				height[i][j]=height[i-1][j]+1;
			}
			int a=rightt[i][j]-leftt[i][j]+1/*横向长度*/,b=min(a,height[i][j]);
			ans1=max(ans1,b*b);ans2=max(ans2,a*height[i][j]);
		}
	cout<<ans1<<endl<<ans2;
	return 0;
}