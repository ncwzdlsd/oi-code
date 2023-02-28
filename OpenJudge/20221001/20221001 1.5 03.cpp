#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	float shu,average,all;
	for(int i=1;i<=n;i++)
	{
		scanf("%f",&shu);
		all+=shu;
	}
	average=all / n;
	printf("%.4f",average);
	return 0;
} 
