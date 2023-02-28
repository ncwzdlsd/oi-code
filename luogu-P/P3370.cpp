#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int mmax=1505,maxn=10005;
ull base=131,prime=23317,mod=212370440130137957;
int N,a[maxn],ans=1;
char s[mmax];
ull hash[maxn],power[maxn];

ull hashh(char s[])
{
	int len=strlen(s);
	ull ans=0;
	for(int i=0;i<len;i++)
		ans=(ans*base+(ull)s[i])%mod+prime;
	return ans;
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
		scanf("%s",s),a[i]=hashh(s);
	sort(a+1,a+N+1);
	for(int i=1;i<N;i++)
		if(a[i]!=a[i+1]) ans++;
	cout<<ans;
	return 0;
}