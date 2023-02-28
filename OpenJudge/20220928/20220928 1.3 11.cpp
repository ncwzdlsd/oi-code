#include <bits/stdc++.h>
using namespace std;

int main()
{
	double a,b;
	int k;
	scanf("%lf %lf",&a,&b);
	k=a / b;
	printf("%g\n",a - k * b);
	return 0;
}
