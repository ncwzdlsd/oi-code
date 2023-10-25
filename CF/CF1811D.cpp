#include <bits/stdc++.h>
using namespace std;
#define int long long

int F[45],n,x,y;

void init()
{
	F[0]=1,F[1]=1;
	for(int i=2;i<=44;i++) F[i]=F[i-1]+F[i-2];
}

bool cut(int siz,int x,int y)
{
	if(siz==1) return 1;
	if(y<=F[siz-1]) return cut(siz-1,y,x);//(x,y)在左
	else if(y>F[siz]) return cut(siz-1,y-F[siz],x);//(x,y)在右
	return 0;
}

void solve()
{
	cin>>n>>x>>y;
	if(cut(n,x,y)) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	int t;cin>>t;
	init();
	while(t--) solve();
	return 0;
}