#include <bits/stdc++.h>
using namespace std;

const int maxn=4e6+5;
char s[maxn],ss[maxn];
int p[maxn];

int init()
{
	int len=strlen(ss+1);
	int j=3;
	s[1]='#',s[2]='$';
	for(int i=1;i<=len;i++)
	{
		s[j++]=ss[i];
		s[j++]='$';
	}
	s[j]='@';
	return j;
}

int manacher()
{
	int len=init(),mid=1,mx=1,ans=1;
	for(int i=1;i<=len;i++)
	{
		if(i<mx) p[i]=min(mx-i,p[mid*2-i]);
		else p[i]=1;//前面的mx一点儿用没用，直接赋为1开始暴力
		while(s[i-p[i]]==s[i+p[i]]) p[i]++;
		if(mx<i+p[i]) mid=i,mx=i+p[i];//更新mid和mx
		ans=max(ans,p[i]-1);
	}
	return ans;
}

int main()
{
	for(int t=1;;t++)
	{
		scanf("%s",ss+1);
		if(ss[1]=='E') return 0;
		printf("Case %d: %d\n",t,manacher());
	}
}