#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int head[maxn],to[maxn],nxt[maxn],cnt;

void add(int x,int y)
{
	to[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}

int main()
{
	int n;cin>>n;
	bool flag=0;
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v),add(v,u);
		if((u==1&&v==2)||(u==2&&v==1)) flag=1;
	}
	if(flag) cout<<0<<endl<<1<<endl<<2;
	else cout<<0<<endl<<2<<endl<<1;
	return 0;
}