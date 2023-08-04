#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x1 x11
#define x2 x22
#define y1 y11
#define y2 y22

int a,b,x1,y1,x2,y2;

bool check(int x,int y)
{
	x-=x2,y-=y2;
	int tmp=a*a+b*b;
	if(!tmp) return x==0&&y==0;
	return (a*x+b*y)%tmp==0&&(a*y-b*x)%tmp==0;
}

signed main()
{
	cin>>x1>>y1>>x2>>y2>>a>>b;
	bool flag=0;
	if(check(x1,y1)||check(-x1,-y1)||check(y1,-x1)||check(-y1,x1)) flag=1;
	printf("%s",flag?"YES":"NO");
	return 0;
}