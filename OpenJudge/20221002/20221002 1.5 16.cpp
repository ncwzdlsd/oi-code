#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N,K;
	double money,price=200;
	scanf("%d %d",&N,&K);
	for(int i=1;i<=20;i++)
	{
		money=i*N;
		if(price<=money)
		{
			printf("%d",i);
			return 0;
		}
		price=price*(1+K/100.0);
//		»òprice=price*(1+(double)K/100);
	}
	if(price>money)
		printf("%s","Impossible");
	return 0;
}
