#include <bits/stdc++.h>
using namespace std;

int main()
{
	int R,Y;
	double M;
	scanf("%d %lf %d",&R,&M,&Y);
	for(int i=1;i<=Y;i++)
	{
		M*=(1+0.01*R);
	} 
	printf("%d",(int)M);
	return 0;
}
