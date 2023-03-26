#include <bits/stdc++.h>
using namespace std;

int main()
{
//	a[5]='\0';
//	cout<<strlen(a)<<endl;
	char a[81];
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==' ')
		{
			cout<<a[i];
		}
		else if((a[i]=='Z')||(a[i]=='z'))
		{
			a[i]=a[i]-25;
			cout<<a[i];
		}
		else if(((65<=a[i])&&(a[i]<90))||((97<=a[i])&&(a[i]<122)))
		{
			a[i]=a[i]+1;
			cout<<a[i];
		}
		else
		{
			cout<<a[i];
		}
	}
	return 0;
}
