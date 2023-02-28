#include <bits/stdc++.h>
using namespace std;

const int maxn=5*1e5+5;
int c[maxn],N;

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
	while(x<=N) c[x]+=v,x+=lowbit(x);
}

int main()
{
	int M,qwq,last;cin>>N>>M;
	for(int i=1;i<=N;i++) cin>>qwq,add(i,qwq-last),last=qwq;
	for(int i=1;i<=M;i++)
	{
		int opt,x,y,k;cin>>opt;
		if(opt==1) cin>>x>>y>>k,add(x,k),add(y+1,-k);
		else cin>>x>>y,cout<<(ask(y)-ask(x-1))<<endl;
	}
	return 0;
}