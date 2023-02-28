#include <bits/stdc++.h>
using namespace std;

int main()
{
	double jieyu,zong=0;
	for(int i=1;i<=12;i++)
	{
		cin>>jieyu;
		zong+=jieyu;
	}
	printf("$%.2lf",zong/12);
	return 0;
}
