#include <bits/stdc++.h>
using namespace std;

int a[10005],b[10005];

int main()
{
	int k;
	while(cin>>k)
	{
		int cnt=0,n=k*k;
		for(int i=1;i<=k;i++)
			if(n%i==0)
				a[++cnt]=n/i,b[cnt]=i;
		cout<<cnt<<endl;
		for(int i=1;i<=cnt;i++)
			printf("1/%d = 1/%d + 1/%d\n",k,k+a[i],k+b[i]);
	}
	return 0;
}