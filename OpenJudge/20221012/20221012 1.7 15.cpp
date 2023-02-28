#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	char s[20];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		if(s[0]>='a'&&s[0]<='z')
		{
			s[0]=s[0]-32;
		}
		for(int i=1;i<strlen(s);i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				s[i]+=32;
			}
		}
		puts(s);
	}
	return 0;
}
