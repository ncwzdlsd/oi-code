#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a[26],b[26];
	int i,j;
	bool flag=true;
	for(i=0;i<26;i++)
	{
		if(a[i]<'A'||a[i]>'Z')
		{
			flag=false;	
		}
		for(j=i+1;j<26;j++)
		{
			if(b[i]==b[j])
			{
				flag=false;
			}
		}
	}
	flag=true;
	char yuan[100],jiami[100],fanyi[100];
	int len1=strlen(yuan),len2=strlen(jiami),len3=strlen(fanyi);
	cin>>jiami>>yuan>>fanyi;
	for(i=0;i<len;i++)
	{
		if()
	}
	return 0;
}
