#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int gold,silver,copper;
	int zong1=0,zong2=0,zong3=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d",&gold,&silver,&copper);
		zong1+=gold;
		zong2+=silver;
		zong3+=copper;
	}
	printf("%d %d %d %d",zong1,zong2,zong3,zong1+zong2+zong3);
	return 0;
}
