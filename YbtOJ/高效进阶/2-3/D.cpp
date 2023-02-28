#include <bits/stdc++.h>
using namespace std;
#define int long long

int nxt[15005],k,ans;
char S[15005],now[15005];

signed main()
{
	scanf("%s",S+1);cin>>k;
	int n=strlen(S+1);
	for(int l=1;l<=n;l++)
	{
		// memset(nxt,0,sizeof(nxt));
		// memset(now,0,sizeof(now));
		for(int i=1;i<=n;i++) nxt[i]=0,now[i]=0;
		for(int i=1;l+i-1<=n;i++)
			now[i]=S[l+i-1];//构造now数组为从i开始的字符串
		int nn=strlen(now+1);
		for(int i=1,j=0;i<=nn;i++)
		{
			while(j&&now[i+1]!=now[j+1]) j=nxt[j];
			if(now[i+1]==now[j+1]) j++;
			nxt[i+1]=j;
		}
		//暴力枚举右端点，看能否满足
		for(int i=0,j=0;i<=nn;i++)
		{
			//从第一位开始匹配，不是i+1是i
			while(j&&now[i+1]!=now[j+1]) j=nxt[j];
			if(now[i+1]==now[j+1]) j++;
			while(j*2>=i+1) j=nxt[j];//
			if(j>=k) ans++;
		}
	}
	cout<<ans;
	return 0;
}