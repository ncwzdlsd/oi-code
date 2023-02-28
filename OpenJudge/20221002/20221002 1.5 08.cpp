#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int angle,surplus=(n-2)*180;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",&angle);
		surplus=surplus-angle;
	}
	printf("%d",surplus);
}
