#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+5;
bool inqueue[maxn];

signed main()
{
	int T;cin>>T;
	while(T--)
	{
	    int n,a,b;cin>>n>>a>>b;
		int sumall=(1+n)*n/2,suml=(1+n/2)*n/4;
		if(a+b>sumall||sumall-suml<b||sumall-suml<a) {cout<<-1<<endl;continue;}
		for(int i=1;i<=n/2;i++) inqueue[i]=true;
		int it=n/2,cnt=0,qwq=n/2;
		while(suml<a)
		{
			inqueue[it]=false;
			inqueue[++it]=true;
			if(it==n-cnt) qwq--,it=qwq,cnt++;
			suml++;
		}
		for(int i=1;i<=n;i++)
			if(inqueue[i]) cout<<i<<' ';
		for(int i=1;i<=n;i++)
			if(!inqueue[i]) cout<<i<<' ';
		cout<<endl;
	}
	return 0;
}