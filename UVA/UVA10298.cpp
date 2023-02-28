#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;
char s[maxn];
int nxt[maxn];

int main()
{
	while(scanf("%s",s+1)&&s[1]!='.')
	{
		int len=strlen(s+1);
		for(int i=1,j=0;i<=len;i++)
		{
			while(j&&s[i+1]!=s[j+1]) j=nxt[j];
			if(s[i+1]==s[j+1]) j++;
			nxt[i+1]=j;
		}
		if(len%(len-nxt[len])==0) cout<<(len/(len-nxt[len]))<<endl;
		else cout<<1<<endl;
	}
	return 0;
}