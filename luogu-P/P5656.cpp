#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}

void exgcd(int a,int b,int &g,int &x,int &y)//g=gcd(a,b)
{
	if(!b) x=1,y=0;
	else 
		exgcd(b,a%b,g,y,x),y-=x*(a/b);
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		int a,b,c,x,y,g=gcd(a,b);cin>>a>>b>>c;
		exgcd(a,b,g,x,y);
		if(c%g) puts("-1");
		else
		{
			x*=c/g;y*=c/g;
			int p=b/g,q=a/g,k;
			if(x<0) k=ceil((1.0-x)/p),x+=p*k,y-=q*k;
			else if(x>=0) k=(x-1)/p,x-=p*k,y+=q*k;
			if(y>0)
				cout<<((y-1)/q+1)<<' '<<x<<' '<<((y-1)%q+1)<<' '<<(x+(y-1)/q*p)<<' '<<y;
			else//无正整数解
				cout<<x<<' '<<(y+q*ceil((1.0-y)/q));
			puts("");
		}
	}
	return 0;
}