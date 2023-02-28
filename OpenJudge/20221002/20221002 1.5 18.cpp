#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int standard1,standard2;
	scanf("%d %d",&standard1,&standard2);
	double standard;
	standard=standard2/(standard1/1.0);
	int data1,data2;
	double data;
	for(int i=2;i<=n;i++)
	{
		scanf("%d %d",&data1,&data2);
		data=data2/(data1/1.0);
		if(data-standard>0.05)
		printf("%s\n","better");
		else if(data-standard<-0.05)
		printf("%s\n","worse");
		else 
		printf("%s\n","same");
	}
	return 0;
}
