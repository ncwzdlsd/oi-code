#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long x, y;
	
	scanf("%lld %lld", &x, &y);
	
	if( (x>=60 && y<60) || (x<60 && y>=60)){
		printf("%d", 1);
	}
	else
	{
		printf("%d", 0);
	}
	
	return 0;
}
