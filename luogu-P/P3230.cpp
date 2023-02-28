#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int a[15];

bool cmp(int a,int b)
{
	return a>b;
}

unsigned long long hashh(int x)
{
	unsigned long long res=x,tmp[15];
	for(int i=1;i<=N;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+x+1,cmp);
	for(int i=1;i<=n;i++) res=res*29+tmp[i];//哈希存储可能性
	return res;
}

// 已经统计到 x 场，总共 n 场
void dfs(int x,int n)
{
	if(a[x]>s*(n-x)) return;
}

int main()
{
	int N;cin>>N;
	for(int o=1;i<=N;i++) cin>>a[i];
	return 0;
}