#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2050;
int n,m,t[maxn][maxn],ti[maxn][maxn],tj[maxn][maxn],tij[maxn][maxn];

int lowbit(int x){return x&(-x);}

void add(int x,int y,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			t[i][j]+=v,ti[i][j]+=x*v,tj[i][j]+=y*v,tij[i][j]+=x*y*v;
}

int ask(int x,int y)
{
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			res+=(x+1)*(y+1)*t[i][j]-ti[i][j]*(y+1)-tj[i][j]*(x+1)+tij[i][j];
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int op;
	while(cin>>op)
	{
		int a,b,c,d,x;cin>>a>>b>>c>>d;
		if(op==1) cin>>x,add(a,b,x),add(c+1,d+1,x),add(a,d+1,-x),add(c+1,b,-x);
		else cout<<ask(c,d)-ask(c,b-1)-ask(a-1,d)+ask(a-1,b-1)<<'\n';
	}
	return 0;
}