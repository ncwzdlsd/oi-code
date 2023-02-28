#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
char s[maxn];
int nxt[maxn],out[maxn];

int main()
{
	int n,k;cin>>n>>k;
	scanf("%s",s+1);
	for(int i=1,j=0;i<=n;i++)
	{
		while(j&&s[i+1]!=s[j+1]) j=nxt[j];
		if(s[i+1]==s[j+1]) j++;
		nxt[i+1]=j;
	}
	for(int i=1;i<=n;i++)
	{
		int now=i-nxt[i],tim=i/now;
		if(i%now) out[i]=((tim/k-tim%k)>0);
		else out[i]=((tim/k-tim%k)>=0);
	}
	for(int i=1;i<=n;i++) cout<<out[i];
	return 0;
}