#include <bits/stdc++.h>
using namespace std;

int main()
{
	int chang,kuan;
	char a;
	int can;
	scanf("%d %d %c %d",&chang,&kuan,&a,&can);
	for(int i=1;i<=chang;i++)
	{
		if(can==1)
		{
			for(int j=1;j<=kuan;j++)
			{
				cout<<a;
			} 
		}
		else
		{
			for(int j=1;j<=kuan;j++)
			{
				if(i!=1&&i!=chang&&j!=1&&j!=kuan)
				{
					printf(" ");
				}
				else
				{
					printf("%c",a);
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
