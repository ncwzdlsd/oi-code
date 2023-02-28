#include <bits/stdc++.h>
using namespace std;

int main()
{
	char a1[2000],b1[2000];
	int a[2000],b[2000],c[2000],lena,lenb,lenc;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	
	cin.getline(a1,201);
	cin.getline(b1,201);
	lena=strlen(a1);
	lenb=strlen(b1);
	for(int i=0;i<lena;i++)
	{
		a[lena-i]=a1[i]-48;
	}
	for(int i=0;i<lenb;i++)
	{
		b[lenb-i]=b1[i]-48;
	}
	
	int x=0;
	for(lenc=1;lenc<=lena||lenc<=lenb;lenc++)
	{
		c[lenc]=a[lenc]+b[lenc]+x;
		x=c[lenc]/10;
		c[lenc]%=10;
	}
	c[lenc]=x;
	
//	if(c[lenc]==0&&lenc>1)
//	{
//		lenc--;
//	}
	
	bool f=false;
	
	for(int i=lenc;i>0;i--)
	{
		if(c[i] != 0)
		{
			f=true;
		}
		
		if(f)		
			cout<<c[i];
	}
	
	if(!f)
		cout<<"0"<<endl;
		
	return 0;
}
