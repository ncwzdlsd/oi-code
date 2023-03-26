#include <bits/stdc++.h>
using namespace std;

int a[6][6];
int i,j;
int da[6],xiao[6];

int main()
{
	// wait for input 5X5
	// a[1][0]-a[0][5]
	// a[2][0]-a[1][5]
	// ...
	// a[5][0]-a[5][5]
	for(i=1;i<=5;i=i+1)
	{
		for(int j=1;j<=5;j=j+1)
		{
			cin>>a[i][j];
		}
	}
	
	for(i=1;i<6;i++)
	{
		da[i]=a[i][1];
		xiao[i]=a[1][i];
	}
	
	for(i=1;i<=5;i=i+1)
	{
		for(j=1;j<=5;j=j+1)
		{
			if(a[i][j]>da[i])
			{
				da[i]=a[i][j];
			}
		}
	}
	
	for(j=1;j<=5;j=j+1)
	{
		for(i=1;i<=5;i=i+1)
		{
			if(a[i][j]<xiao[j])
			{
				xiao[j]=a[i][j];
			}
		}
	}
	
	bool notfound = true;
	for(i=1;i<=5;i=i+1)
	{
		for(j=1;j<=5;j=j+1)
		{
			if((a[i][j]==da[i])&&(a[i][j]==xiao[j]))
			{
				cout<<i<<" "<<j<<" "<<a[i][j];
				notfound = false; 
			}
		}
	}
	if(notfound)
	{
		cout<<"not found";
	}
}
