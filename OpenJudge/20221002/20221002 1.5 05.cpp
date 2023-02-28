#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,max=0,score;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&score);
		if(max<score)
		{
			max=score;
		}
	}
	printf("%d",max);
	return 0;
} 
