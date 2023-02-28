#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
char a[maxn],b[maxn];
int nxt[maxn],n,m;

int main()
{
	int cnt=0;
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1);
	for(int i=1,j=0;i<m;i++)
	{
		while(j&&b[i+1]!=b[j+1]) j=nxt[j];
		if(b[i+1]==b[j+1]) j++;
		nxt[i+1]=j;
	}
	for(int i=0,j=0;i<n;i++)
	{
		while(j&&a[i+1]!=b[j+1]) j=nxt[j];
		if(a[i+1]==b[j+1]) j++;//如果当前位能匹配
		if(j==m) cnt++;
	}
	cout<<cnt;
	return 0;
}