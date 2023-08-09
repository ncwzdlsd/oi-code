#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int a[maxn],c[maxn],op[maxn],l[maxn],r[maxn];

int lowbit(x){return x&(-x)}

int ask(int x)
{
	int res=0;
	while(x) res+=c[x],x-=lowbit(x);
	return res;
}

void add(int x,int v){while(x<=n) c[x]+=v,x+=lowbit(x);}

bool check(mid)
{
	for(int i=1;i<=m;i++)
	{
		int cnt=ask(r[i])-ask(l[i]-1);
		if(!op[i]) add(r[i]-cnt+1,1),add(r[i]+1,-1),add(l[i],0),add(r[i]-cnt+1,0);
		else add(l[i],1),add(l[i]+cnt,-1),add(l[i]+cnt,0),add(r[i]+1,0);
	}
}

signed main
{
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>op[i]>>l[i]>>r[i];
	int p;cin>>p;
	for(int i=1;i<=m;i++)
	{
	}
	return 0;
}