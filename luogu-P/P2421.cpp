#include<bits/stdc++.h>
using namespace std;

const int maxn=20;
int n,s[maxn],p[maxn],l[maxn];

int exgcd(int a,int b,int &x,int &y) 
{
	if(!b) {x=1,y=0;return a;}
	int ans=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return ans;
}

bool check(int m) 
{
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) 
	{
		int a=p[i]-p[j],b=m,c=s[j]-s[i],x,y;
		int d=exgcd(a,b,x,y);
		if(c%d) continue;
		a/=d,b/=d,c/=d;
		if(b<0) b=-b;
		x=(x*c%b+b)%b;
		if(x<=l[i]&&x<=l[j]) return 0;
	}
	return 1;
}
int main() 
{
	cin>>n;
	int maxx=0;
	for(int i=1;i<=n;++i) cin>>s[i]>>p[i]>>l[i],maxx=max(maxx,s[i]);
	for(int i=maxx;;++i) if(check(i)) cout<<i<<endl,exit(0);
	return 0;
}