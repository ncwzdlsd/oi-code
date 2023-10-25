#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	double ans1,ans2,H,h,D;
	cin>>T;
	while(T--)
	{
		cin>>H>>h>>D;
		double a=sqrt(D*(H-h));
		if(a>D)
		ans1=D+H-(D+(H-h));
		else if(a<=D)
			ans1=(D+H-(2*a));
		if(a<D*(H-h)/H) ans1=0;
		ans2=D-D*(H-h)/H;
		printf("%.3lf\n",max(ans1,ans2));
	}
	return 0;
}
