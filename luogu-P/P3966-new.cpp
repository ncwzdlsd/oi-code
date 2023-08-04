#include<bits/stdc++.h>
using namespace std;
#define int long long

char ss[210][1000005];
int p[1000005],n;

void pre(char *s)
{
	memset(p,0,sizeof p);
	int h=strlen(s+1);
	for(int i=1,j=0;i<=h;i++)
	{
		while(j>0&&s[i+1]!=s[j+1]) j=p[j];
		if(s[i+1]==s[j+1]) ++j;
		p[i+1]=j;
	}
}

int kmp(char *b,char *a)
{
	int ans=0,j=0,n1=strlen(a+1),m1=strlen(b+1);
	for(int i=0;i<=n1;i++)
	{
		while(j>0&&b[j+1]!=a[i+1]) j=p[j];
		if(b[j+1]==a[i+1]) j++;
		if(j==m1) ans++,j=p[j];
	}
	return ans;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)	
		scanf("%s",ss[i]+1);
	for(int i=1;i<=n;i++)
	{
		int summ=0;
		pre(ss[i]);
		for(int j=1;j<=n;j++) summ+=kmp(ss[i],ss[j]);	
		cout<<summ<<endl;
	}
	return 0;
}