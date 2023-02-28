#include <bits/stdc++.h>
using namespace std;

int main()
{
	float f1=-0.123456789;
	float f2=12345.123456789;
	
	printf("%.5f\n",f1);
	printf("%.5f\n", f2);
	printf("%.5f\n", 0*f1);
	
	cout<<endl<<"----------------------------------"<<endl;
	
	double d1=-0.123456789;
	double d2=12345.123456789;
	
	printf("%.5lf\n", d1);
	printf("%.5lf\n",d2);
	printf("%.5lf\n", 0*d2);		
}
