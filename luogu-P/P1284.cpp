#include <bits/stdc++.h>
using namespace std;

int l[45];
bool f[805][805];
double ans;

double work(double a,double b,double c)
{
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

bool check(int a,int b,int c)
{
	if(a+b>c&&a+c>b&&b+c>a) return 1;
	return 0;
}

int main()
{
	int n,cc,i,j,k;cin>>n;
	for(i=1;i<=n;i++) cin>>l[i],cc+=l[i];
	f[0][0]=1;
	for(k=1;k<=n;k++)
		for(i=cc/2;i>=0;i--)
			for(j=cc/2;j>=0;j--)
			{
				if(i-l[k]>=0&&f[i-l[k]][j]) f[i][j]=1;
				else if(j-l[k]>=0&&f[i][j-l[k]]) f[i][j]=1;
			}
	ans=-1;
	for(i=cc/2;i>0;i--)
		for(j=cc/2;j>0;j--)
		{
			if(!f[i][j]) continue;
			if(!check(i,j,cc-i-j)) continue;
			ans=max(ans,work(i,j,cc-i-j));
		}
	if(ans!=-1) cout<<(long long)(ans*100);
	else cout<<-1;
	return 0;
}