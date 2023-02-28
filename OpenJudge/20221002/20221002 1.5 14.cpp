#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	double x;
	scanf("%lf %d",&x,&n);
	for(int i=1;i<=n;i++)
	{
		x=x*(1+0.001);
	}
	printf("%.4lf",x);
	return 0;
}
