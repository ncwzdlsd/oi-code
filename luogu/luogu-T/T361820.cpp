#include <bits/stdc++.h>
using namespace std;
#define int long long

int f[25];

int quickpow(int a,int b)
{
    int t=1,y=a;
    while(b)
    {
        if(b&1) t=t*y;
        y*=y;
        b>>=1;
    }
    return t;
}

void init()
{
	f[1]=1,f[2]=1;
	for(int i=3;i<=25;i++) f[i]=f[i-1]*2;
}

signed main()
{
	int T;cin>>T;
	init();
	while(T--)
	{
		int n,x;cin>>n>>x;
		if(x%quickpow(2,(n-2))==0) cout<<x<<endl;
		else if(x%2) cout<<(f[n]*x)<<endl;
		else
		{
			int p=x;
			while(1)
			{
				if(p%2!=0) break;
				p=p/2;
			}
			cout<<f[n]*p<<endl;
		}
	}
	return 0;
}