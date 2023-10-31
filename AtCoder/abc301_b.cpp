#include <bits/stdc++.h>
using namespace std;

int a[105],N;

int main()
{
	cin>>N;
	cin>>a[1];cout<<a[1]<<' ';
	for(int i=2;i<=N;i++) 
	{
		cin>>a[i];
		if(abs(a[i]-a[i-1])==1) {cout<<a[i]<<' ';continue;}
		else
		{
			if(a[i]>a[i-1]) for(int j=a[i-1]+1;j<=a[i];j++) cout<<j<<' ';
			else for(int j=a[i-1]-1;j>=a[i];j--) cout<<j<<' ';
		} 
	}
	return 0;
}