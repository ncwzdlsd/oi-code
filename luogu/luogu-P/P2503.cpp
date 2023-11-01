#include <bits/stdc++.h>
using namespace std;

int a[25],b[25];
mt19937 rd(time(0));

int main()
{
	int n,m;cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	double xx=(double)sum/m;
	double t1=clock(),t2=clock();
	double ans=1e9;
	while((double)(t2-t1)/CLOCKS_PER_SEC<0.95)
	{
		shuffle(a+1,a+n+1,rd);
		memset(b,0,sizeof b);
		int minid=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
				if(b[minid]>b[j]) minid=j;
			b[minid]+=a[i];minid=1;
		}
		double tmp=0;
		for(int i=1;i<=m;i++) tmp+=(double)(xx-b[i])*(xx-b[i]);
		tmp/=m,ans=min(ans,tmp);
		t2=clock();
	}
	printf("%.2lf",sqrt(ans));
	return 0;
}