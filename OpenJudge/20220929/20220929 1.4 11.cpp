#include <bits/stdc++.h>
using namespace std;

int main()
{
	float x1,x2;
	
	float a, b, c;
	
	scanf("%f %f %f", &a, &b, &c);

	
	if(b*b == 4*a*c)
	{
		x1=(-1)*b/(2*a);	
		x2=(-1)*b/(2*a);		
		
		printf("%s%.5f", "x1=x2=",x1);
	}
	else if(b*b > 4*a*c)
	{
		x1=(-1*b + sqrt(b*b-4*a*c))/(2*a);
		x2=(-1*b - sqrt(b*b-4*a*c))/(2*a);
		
		if(x1>x2)
			printf("%s%.5f%s%.5f", "x1=",x1,";x2=",x2);
		else
			printf("%s%.5f%s%.5f", "x1=",x2,";x2=",x1);
		
	}
	else
	{		
		if(b==0)
			x1=0;
		else
			x1=(-1)*b/(2*a);
		x2=sqrt(4*a*c-b*b)/abs(2*a);
				
		printf("%s%.5f%s%.5f%s%.5f%s%.5f%s", "x1=",x1,"+",x2,"i;x2=",x1,"-",x2,"i");
	}
	
	return 0;
}
