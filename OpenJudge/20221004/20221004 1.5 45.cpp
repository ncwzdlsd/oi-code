#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,money=0,day=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if((n-day)<i)
		{
			money+=i*(n-day);
			break;
		}
		money+=i*i;
		day+=i;
	}
	printf("%d",money);
	return 0;
}
