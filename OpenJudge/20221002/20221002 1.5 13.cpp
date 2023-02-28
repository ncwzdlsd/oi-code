#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,n,result=1;
	scanf("%d %d",&a,&n);
	for(int i=1;i<=n;i++)
	{
		result=a*result;
	}
	printf("%d",result);
	return 0;
}
