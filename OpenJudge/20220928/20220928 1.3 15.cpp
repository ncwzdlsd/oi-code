#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	if(y%x==0)
	printf("%d\n",n-y/x);
	else
	printf("%d\n",n-y/x-1);
	return 0;
}
