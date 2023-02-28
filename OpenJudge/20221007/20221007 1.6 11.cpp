#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	char a1[201],b1[201],n[201];
	int a[201],b[201],c[201];
	int lena,lenb,lenc;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%s %s",a1,b1);
	lena=strlen(a1);
	lenb=strlen(b1);
	int i;
	for(i=0;i<lena;i++)
	{
		a[lena-i]=a1[i]-48;
	}
	for(i=0;i<lenb;i++)
	{
		b[lenb-i]=b1[i]-48;
	}
	for(i=1;i<=lena;i++)
	{
		if(a[i]<b[i])
		{
			a[i]+=10;
			a[i+1]--;
		}
		c[i]=a[i]-b[i]; 
	}
	lenc=i;
	for(;c[lenc]==0&&lenc>1;)
	{
		lenc--;
	}
	for(int i=lenc;i>0;i--)
	{
		cout<<c[i];
	}
	cout<<endl;
	return 0;
} 
