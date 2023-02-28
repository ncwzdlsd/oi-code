#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[80];
	cin.getline(a,100);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]=a[i]-32;
		}
		else if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=a[i]+32;
		}
		printf("%c",a[i]);
	}
	return 0;
}
