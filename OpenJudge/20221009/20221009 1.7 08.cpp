#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[30];
	char a,b;
	cin>>s>>a>>b;
	int len=strlen(s);
	int i;
	for(i=0;i<len;i++)
	{
		if(s[i]==a)
		{
			s[i]=b;
		}
	}
	cout<<s;
	return 0;
}

