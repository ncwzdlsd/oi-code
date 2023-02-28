#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,m;
	scanf("%d %d",&N,&m);
	int number,sum=0;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&number);
		if(number==m)
		sum+=1;
	}
	printf("%d",sum);
	return 0;
}
