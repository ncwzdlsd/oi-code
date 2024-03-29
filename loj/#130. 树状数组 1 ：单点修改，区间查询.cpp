#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int n,q,c[maxn];

int lowbit(int x){return x&(-x);}

void add(int x,int v){while(x<=n) c[x]+=v,x+=lowbit(x);}

int ask(int x)
{
	int res=0;
	while(x) res+=c[x],x-=lowbit(x);
	return res;
}

signed main()
{
	cin>>n>>q;
	for(int i=1,a;i<=n;i++) cin>>a,add(i,a);
	while(q--)
	{
		int op,i,x,l,r;cin>>op;
		if(op==1) cin>>i>>x,add(i,x);
		else cin>>l>>r,cout<<ask(r)-ask(l-1)<<'\n';
	}
	return 0;
}