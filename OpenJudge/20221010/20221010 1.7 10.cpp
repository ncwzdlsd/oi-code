#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[200];
	cin.getline(s,200);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]<='Z'&&s[i]>='A')
		{
			s[i]=((int)s[i]-'A'+21)%26+'A';
		}
		else 
		{
		}
	}
	cout<<s;
} 
