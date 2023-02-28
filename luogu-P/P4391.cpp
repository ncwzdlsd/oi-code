#include<bits/stdc++.h>
using namespace std;
const int maxn=0x3f3f3f;
int n,nxt[maxn];
char ss[maxn];
int main()
{
	scanf("%d%s",&n,ss+1);
	int j=0;
	for(int i=2;i<=n;++i)
	{
		while(j&&ss[i]!=ss[j+1]) j=nxt[j];
		if(ss[i]==ss[j+1]) ++j;
		nxt[i]=j;
	}
	printf("%d",n-nxt[n]);
	return 0;
}