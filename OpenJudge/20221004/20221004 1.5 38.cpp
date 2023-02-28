#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	if(n==0)
	{
		printf("0");
		return 0;
	}
	int c;
	for(int i=n;i>0;i--)
	{
		scanf("%d",&c);
		printf("%d",c*i);
	}
	return 0;
}
