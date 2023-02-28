#include <bits/stdc++.h>
using namespace std;

int main()
{
	char t[105][105];
	int n=0; 
	while(scanf("%s",t[++n])!=EOF);
	n--;
	for(int i=1;i<=n-2;i++)
	{
		if(strcmp(t[i],t[n-1])==0) printf((i==1)?"%s":" %s",t[n]); 
		else printf((i==1)?"%s":" %s",t[i]);
	}
	return 0;
}