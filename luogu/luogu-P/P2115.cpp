#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int M[maxn],tot,N;

bool check(double x)
{
	double sum=0,mx=-0x3f3f3f3f;
	for(int i=2;i<N;++i)
		sum=max(sum,0.0),sum+=M[i]-x,mx=max(mx,sum);
	sum=0;
	return mx<=(tot-N*x);
}

int main()
{
	cin>>N;
	double l=0,r;
	for(int i=1;i<=N;i++) cin>>M[i],r=max(r,(double)M[i]),tot+=M[i];
	for(int t=1;t<=50;++t)
	{
		double mid=(l+r)/2.0;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.3lf",l);
	return 0;
}