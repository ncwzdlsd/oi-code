#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int shu,sum;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&shu);
		sum+=shu;
	}
	printf("%d %.5lf\n",sum,(double)sum / n);
	return 0;
} 
