#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5*1e5+5;
int c[maxn],a[maxn],n;

int lowbit(int x)
{
	return x&(-x);
}

int ask(int x)//查询x的前缀和
{
	int res=0;
	while(x) res+=c[x],x-=lowbit(x);
	return res;
}

void add(int x,int v)//把点x增加v
{
	while(x<=n) c[x]+=v,x+=lowbit(x);
}

signed main()
{
	int m;cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int k,a,b;cin>>k>>a>>b;
		if(!k) add(a,b);
		else cout<<(ask(b)-ask(a-1))<<endl;
	}
	return 0;
}