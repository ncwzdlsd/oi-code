#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[256];
	int len,i;
	len=strlen(a);
	bool flag1=true,flag2=true;
	cin>>a;
	if((a[0]>='0')&&(a[0]<='9'))
	{
		flag1=false;
	}
	for(i=0;i<len;i++)
	{
		if((a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||(a[i]=='_')||(a[i]>='0'&&a[i]<='9'));
		else
		{
			flag2=false;
		}
	}
	if((flag1==true)&&(flag2==true))
	{
		cout<<"yes";
	}
	else
	{
		cout<<"no";
	}
	return 0;	
}
