#include<bits/stdc++.h>
using namespace std;
const int N=1000005
char a[N],b[N];
int nxt[N],f[N],la,lb,res,zhan[N],top;
int main()
{
	int i,j;
	scanf("%s%s",a+1,b+1);
	la=strlen(a+1),lb=strlen(b+1);
	for(i=2,j=0;i<=lb;i++) 
	{
		while(j&&b[i]!=b[j+1]) j=nxt[j];
		if(b[i]==b[j+1]) j++;
		nxt[i]=j;
	}
	for(i=1,j=0;i<=la;i++) 
	{
		while(j&&a[i]!=b[j+1]) j=nxt[j];
		if(a[i]==b[j+1]) j++;
		f[i]=j;
		zhan[++top]=i;
		if(j==lb) top-=lb,j=f[zhan[top]];
	}
	for(i=1;i<=top;i++) cout<<a[zhan[i]];
	return 0;
}