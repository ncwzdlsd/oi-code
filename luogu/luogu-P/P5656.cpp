#include <bits/stdc++.h>
using namespace std;
#define int long long

void exgcd(int a,int b,int &g,int &x,int &y)//g=gcd(a,b)
{
	if(!b) x=1,y=0,g=a;
	else exgcd(b,a%b,g,y,x),y-=x*(a/b);
}

int gcd(int a,int b)
{
	return (a%b==0)?b:gcd(b,a%b);
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		int a,b,c,x,y;
		cin>>a>>b>>c;
		int g=__gcd(a,b);
		if(c%g) puts("-1");
		else
		{
			exgcd(a,b,g,x,y);
			
		}
	}
	return 0;
}