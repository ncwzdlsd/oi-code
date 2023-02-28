#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e7+5;
char a[maxn],b[maxn];
long long za[maxn],zb[maxn];

int main()
{
	scanf("%s%s",a,b);
	int la=strlen(a),lb=strlen(b);
	zb[0]=lb;
	for(int i=1,l=0,r=0;i<lb;++i)
	{
		if(i<=r&&zb[i-l]<r-i+1) zb[i]=zb[i-l];//因为不确定下一位是否相等，所以直接继承z[i-l]
		else
		{
			zb[i]=max(0,r-i+1);//0说明i>r，r-i+1说明超出匹配区间
			while(i+zb[i]<lb&&b[zb[i]]==b[i+zb[i]]) ++zb[i];
		}
		if(i+zb[i]-1>r) l=i,r=i+zb[i]-1;
	}
	for(int i=0;i<la;++i)//求a关于模板串b的z[0]
	{
		if(b[i]==a[i]) ++za[0];
		else break;
	}
	for(int i=1,l=0,r=0;i<la;++i)
	{
		if(i<=r&&zb[i-l]<r-i+1) za[i]=zb[i-l];
		else
		{
			za[i]=max(0,r-i+1);
			while(i+za[i]<la&&b[za[i]]==a[i+za[i]]) ++za[i];
		}
		if(i+za[i]-1>r) l=i,r=i+za[i]-1;
	}
	long long ans=0,bp=0;
	for(int i=0;i<la;i++) ans^=(i+1)*(za[i]+1);
	for(int i=0;i<lb;i++) bp^=(i+1)*(zb[i]+1);
	cout<<bp<<endl<<ans;
	return 0;
}