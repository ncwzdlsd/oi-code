#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
int n,q,c[maxn],a[maxn],s[maxn];

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
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	while(q--)
	{
		int op;cin>>op;
		if(op==1)
		{
			int l,r,x;cin>>l>>r>>x;
			add(l,x),add(r+1,-x);
		}
		else
		{
			int l,r;cin>>l>>r;
			cout<<s[r]-s[l-1]+ask(r)-ask(l-1)<<'\n';
		}
	}
	return 0;
}