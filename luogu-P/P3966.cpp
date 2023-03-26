#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;
char ss[205][maxn],nxt[maxn];

void pre(char *s)
{
	memset(nxt,0,sizeof nxt);
	int len=strlen(s+1);
	for(int i=1,j=0;i<=len;i++)
	{
		while(j&&s[i+1]!=s[j+1]) j=nxt[j];
		if(s[i+1]==s[j+1]) ++j;
		nxt[i+1]=j;
	}
}

int kmp(char *b,char *a)
{
	int m=strlen(b+1),n=strlen(a+1),cnt=0;
	for(int i=0,j=0;i<=n;i++)
	{
		while(j&&a[i+1]!=b[j+1]) j=nxt[j];
		if(a[i+1]==b[j+1]) j++;
		if(j==m) cnt++,j=nxt[j];
	}
	return cnt;
}

signed main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++) cin>>ss[i]+1;
	for(int i=1;i<=N;i++)
	{
		int ans=0;
		pre(ss[i]);
		for(int j=1;j<=N;j++) 
			ans+=kmp(ss[i],ss[j]);
		cout<<ans<<endl;
	}
	return 0;
}