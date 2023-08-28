#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int a[maxn],q[maxn],k[maxn],pr[maxn],f[maxn],s[maxn],L,N,P;
char str[maxn][35];

int quickpow(int a,int b)
{
	int t=1,y=a;
	while(b)
	{
		if(b&1) t*=y;
		y*=y,b>>=1;
	}
	return t;
}

int calc(int i,int j)
{return f[j]+quickpow(abs(s[i]-s[j]-L),P);}

int work(int x,int y)
{
	int l=x,r=N+1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(calc(mid,x)>=calc(mid,y)) r=mid;
		else l=mid+1;
	}
	return l;
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>N>>L>>P;
		for(int i=1;i<=N;i++)
			if(cin>>str[i]) s[i]=s[i-1]+strlen(str[i])+1;
		int h=t=1;
		for(int i=1;i<=N;i++)
		{
			q[i]=0;
			while(h<t&&k[h]<=i)++h;
            f[i]=calc(i,q[h]);pr[i]=q[h];
            while(h<t&&k[t-1]>=work(q[t],i)) --t;
            k[t]=work(q[t],i);q[++t]=i;
		}
		if(f[n]>1e18)puts("Too hard to arrange");
        else
        {
            printf("%.0Lf\n",f[n]);
            int t=0;
            q[0]=N;
            for(int i=N;i;q[++t]=i=pr[i]);
            for(;t;--t)
            {
                for(i=q[t]+1;i<q[t-1];++i)
                    printf("%s ",str[i]);
                puts(str[i]);
            }
        }
        puts("--------------------");
	}
	return 0;
}