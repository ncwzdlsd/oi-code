#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	double x,y,d,t=0;
	int people;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf %d",&x,&y,&people);
		d=sqrt(1.0*x*x+1.0*y*y);
		t+=1.5*people+(d*2)/50.0;
	}
	cout<<ceil(t);
	return 0;
}
