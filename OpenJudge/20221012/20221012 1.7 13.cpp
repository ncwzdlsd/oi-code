#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[100];
	cin.getline(a,100);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]=a[i]-32;
		}
	}
	for(int i=0;i<len;i++)
	cout<<a[i];
	return 0;
} 
