#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
int s[maxn];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&s[i+1]!=s[j+1]) j=nxt[j];
		if(s[i+1]==s[j+1]) j++;
		nxt[i+1]=j;
	}
	//用 DP 解决长度为 i 的前缀字符串长度的最小值
	//f[i]=i或f[nxt[i]]
	//考虑如果nxt[i]为0，f[i]必须全部覆盖即长度为i
	//还要维护每个子串能到达的最后位置，用数组end记录
	for(int i=2;i<=n;i++)
	{
		f[i]=i;
		if(end)
	}
	return 0;
}