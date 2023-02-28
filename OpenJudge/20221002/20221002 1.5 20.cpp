#include <bits/stdc++.h>
using namespace std;

int main()
{
	double h;
	scanf("%lf",&h);
	double result,sum=h;
	for (int i=2;i<=10;i++)
	{
		h=h/2;
		sum+=2*h;
	}
	printf("%g\n%g\n",sum,h/2);
	return 0;
}
