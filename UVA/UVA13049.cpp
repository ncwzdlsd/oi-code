#include <bits/stdc++.h>
using namespace std;

char a[105],b[105];
int T,ans[205],n;

int main()
{
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		int sum=0;
		scanf("%d%s%s",&n,a,b);
		for(int j=0;j<n;j++)
			sum+=min(abs(a[j]-b[j]),10-abs(a[j]-b[j]));
		ans[i]=sum;
	}
	for(int i=1;i<=T;i++)
		printf("Case %d: %d\n",i,ans[i]);
	return 0;
}