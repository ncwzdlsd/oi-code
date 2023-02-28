#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[50];
	cin.getline(a,50);
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]=(a[i]-'a'+3)%26+'a';
			a[i]=a[i]-32;
		}
		else if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=(a[i]-'A'+3)%26+'A';
			a[i]=a[i]+32;
		}
	}
	for(int i=len-1;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	return 0;
}
