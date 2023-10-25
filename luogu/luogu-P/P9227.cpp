#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
int a[maxn],b[maxn],n,k;

int calc(int i)
{
	int res=b[1];
	for(int j=2;j<=n;i++)
		if(j!=i) res^=b[i];
	return res;
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
		while(k--)
		{
			for(int i=1;i<=n;i++) a[i]=calc(i);
			for(int i=1;i<=n;i++) b[i]=a[i];
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<endl;
	}
	return 0;
}