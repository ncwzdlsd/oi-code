#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2050;
ll n,m,c[maxn][maxn];

int lowbit(int x){return x&(-x);}

void add(int x,int y,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			c[i][j]+=k;
}

ll query(int x,int y)
{
	ll sum=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j)) sum+=c[i][j];
	return sum;
}

int main()
{
	cin>>n>>m;
	int opt;
	while(cin>>opt)
	{
		if(opt==1) 
		{
			int a,b,c,d,x;cin>>a>>b>>c>>d>>x;
			add(a,1),add(b+1,1),add(c,1),add(d+1,1);
		}
		else 
		{
			int a,b,c,d;cin>>a>>b>>c>>d;
			cout<<query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1)<<endl;
		}
	}
	return 0;
}