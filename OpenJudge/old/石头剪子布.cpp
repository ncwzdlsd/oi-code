#include <bits/stdc++.h>
using namespace std;

int N,NA,NB,a[100],b[100],i,j,Awin=0,Bwin=0;

int main()
{	
//	cout<<"0表示“石头”，2表示“剪刀”，5表示“布”"<<endl;
	
	cin>>N>>NA>>NB;
	
	if(NA>=100||NB>=100||N>=100||NA<1||NB<1||N<1)
	{
		return 0;
	}
	// wait for input about NA
	for(i=0;i<NA;i=i+1)
	{
		cin>>a[i];
	}
	// wait for input about NB
	for(j=0;j<NB;j=j+1)
	{
		cin>>b[j];
	}
		
	for(i=NA;i<N;i=i+1)
	{
		a[i]=a[i%NA];
		
//		cout<<a[i]<<",";
	}
	
//	cout<<endl;
	
	for(j=NB;j<N;j=j+1)
	{
		b[j]=b[j%NB];
		
//		cout<<b[j]<<",";
	}
	
//	cout<<endl;
	
	
	for(i=0;i<N;i=i+1)
	{
		if((a[i]==0&&b[i]==2)||(a[i]==2&&b[i]==5)||(a[i]==5&&b[i]==0))// a win
		{
			Awin=Awin+1;
		}
		else if(a[i]==b[i])// draw
		{
		}
		else// b win
		{
			Bwin=Bwin+1;
		}
	}
	
	if(Awin>Bwin)
	{
		cout<<"A";
	}
	else if(Awin<Bwin)
	{
		cout<<"B";
	}
	else
	{
		cout<<"draw";
	}
	return 0;
}
