#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int c[maxn],n;

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
	int w;cin>>n>>w;
	while(w--)
	{
		char opt;
		int a,b;
		cin>>opt;
		if(opt=='x')
			cin>>a>>b,add(a,b);
		else
			cin>>a>>b,cout<<(ask(b)-ask(a-1))<<endl;
	}
	return 0;
}