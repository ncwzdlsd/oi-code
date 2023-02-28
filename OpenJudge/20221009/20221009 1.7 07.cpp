#include <bits/stdc++.h>
using namespace std;

int main()
{
	char s[255];
	cin.getline(s,255);
	int l=strlen(s);
	for(int i=0;i<l;i++)
	{
		if(s[i]=='A')
		{
			cout<<'T';
		}
		if(s[i]=='T')
		{
			cout<<'A';
		}
		if(s[i]=='G')
		{
			cout<<'C';
		}
		if(s[i]=='C')
		{
			cout<<'G';
		}
	}
	return 0;
}
