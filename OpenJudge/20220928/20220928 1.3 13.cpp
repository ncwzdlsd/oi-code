#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	a=n/100;
	b=n/10-10*a;
	c=n-100*a-10*b;
	printf("%d%d%d",c,b,a);
	return 0;	
}
