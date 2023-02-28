#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000005,P=10,mod=123456791;
int power[N]={1},hh[N],n;
char s[N];
inline int hashh(int a,int b)//区间a到b的哈希值，用于判断等式能否成立
{
	return (hh[b]-hh[a-1]*power[b-a+1]%mod+mod)%mod;
}
inline int check(int a,int b)//判断前导0和非空
{
	if(!a) return 0;
	if(b-a!=1&&s[a+1]=='0') return 0;
	if(b!=n-1&&s[b+1]=='0') return 0;	
	return 1;
} 
inline void out(int a,int b)//输出1~a位、a+1~b位组成的式子
{
	for(int i=1;i<=a;i++) cout<<s[i];	
	cout<<'+';
	for(int i=a+1;i<=b;i++) cout<<s[i];
	cout<<'=';
	for(int i=b+1;i<=n;i++) cout<<s[i];
	exit(0);
} 
main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		hh[i]=(hh[i-1]*P%mod+s[i]-'0')%mod;
	for(int i=1;i<=n;i++)
		power[i]=power[i-1]*P%mod;
	for(int i=n-1;i>=2;i--)
	{
		if(i<n-i)
			continue;
		int sum1=hashh(i+1,n),len=n-i;
		if((hashh(1,len)+hashh(len+1,i))%mod==sum1&&check(len,i)) out(len,i);
		if((hashh(1,len-1)+hashh(len,i))%mod==sum1&&check(len-1,i)) out(len-1,i);
		if((hashh(1,i-len)+hashh(i-len+1,i))%mod==sum1&&check(i-len,i)) out(i-len,i);
		if((hashh(1,i-len+1)+hashh(i-len+2,i))%mod==sum1&&check(i-len+1,i)) out(i-len+1,i);
	}
	return 0;
}