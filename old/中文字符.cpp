#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[10000];
	gets(s);
	int len=strlen(s);
	cout<<"len="<<len<<endl;
	
//	for(int i=0;i<len;i++)
//	{
//		cout<<"ascii:"<<(int)s[i]<<endl;
//		s[i]=s[i]+2;
//		cout<<"ascii new:"<<(int)s[i]<<endl;
//		
//	}
	
	for(int i=0;i<len;i=i+2)
	{
		s[i]=s[i]-2;
		
	}
	cout<<"new"<<s<<endl;
	
}
