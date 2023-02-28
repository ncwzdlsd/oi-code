#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int age;
	float all,average;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&age);
		all+=age;
	}
	average=all / n;
	printf("%.2f",average);
	return 0;
} 
