#include <bits/stdc++.h>
using namespace std;

int a[10],b[10];

int main()
{
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],sum+=((double)100/a[i])*b[i];
	int t;cin>>t;
	if(t<=sum) cout<<"Already Au.",exit(0);
	else for(int i=1;i<=n;i++)
	{
		if(a[i]==b[i]||sum+((double)100/a[i])*(a[i]-b[i])<=t) cout<<"NaN"<<endl;
		else
		{
			int tt=t-sum,pp=(double)100/a[i];
			cout<<tt/pp+1<<endl;
		}
	}
	return 0;
}