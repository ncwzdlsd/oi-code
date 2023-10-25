#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+5;
int nxt[maxn],f[maxn],t[maxn];
char s[maxn];

int main()
{
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&s[i+1]!=s[j+1]) j=nxt[j];
		if(s[i+1]==s[j+1]) j++;
		nxt[i+1]=j;
	}
	f[1]=1;
	for(int i=2;i<=n;++i)
	{
		f[i]=i;
		if(t[f[nxt[i]]]>=i-nxt[i]) f[i]=f[nxt[i]];
		t[f[i]]=i;
	}
	cout<<f[n];
	return 0;
}