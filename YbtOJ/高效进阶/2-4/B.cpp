#include <bits/stdc++.h>
using namespace std;

// 01字典树，由于要找最大异或和，对于每一个节点转化为二进制，不停地找与它相反的节点向下递归，
// 否则继续递归子树

const int maxn=1e5+5,maxm=4*1e6+5;
int a[maxn],t[maxm][2],tot;

void insert(int x)
{
	int p=0;//根节点为0
	for(int i=30;i>=0;--i)//高位的贡献优先
	{
		int qwq=x>>i&1;
		if(!t[p][qwq]) t[p][qwq]=++tot;
		p=t[p][qwq];
	}
}

int query(int x)
{
	int res=0,p=0;
	for(int i=30;i>=0;--i)
	{
		int qwq=x>>i&1;
		if(t[p][!qwq]) p=t[p][!qwq],res=res*2+!qwq;
        else p=t[p][qwq],res=res*2+qwq;
	}
	return res;
}

int main()
{
	int N,ans=0;cin>>N;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=N;i++) insert(a[i]),ans=max(ans,query(a[i])^a[i]);
	cout<<ans;
	return 0;
}