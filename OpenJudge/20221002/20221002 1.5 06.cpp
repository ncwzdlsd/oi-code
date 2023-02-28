#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,max=0,min=10000,score;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&score);
		if(max<=score)
		{
			max=score;
		}
		if(score<=min)
		{
			min=score;
		}
	}
	printf("%d",max-min);
	return 0;
} 
