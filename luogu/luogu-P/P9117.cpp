#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
struct node{int c,t;}a[maxn],b[maxn];

void solve()
{
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=n;i++) a[i]={0,0};
	for(int i=1;i<=m;i++) b[i]={0,0};
	for(int i=1;i<=q;i++)
	{
		int opt,x,c;cin>>opt>>x>>c;
		if(!opt) a[x].c=c,a[x].t=i;
		else b[x].c=c,b[x].t=i;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i].t>b[j].t) cout<<a[i].c<<' ';
			else cout<<b[j].c<<' ';
		}
		cout<<"\n";
	}
}

int main()
{
	int T;cin>>T;
	while(T--) solve();
	return 0;
}