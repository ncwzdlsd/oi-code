#include<bits/stdc++.h>
using namespace std;
#define int long long
queue<int>a;queue<int>b;queue<int>c;
bool cmp(int x,int y){return x>y;}
signed main()
{
    int n,m,q,u,v,t,x,y,aa[100005];
	cin>>n>>m>>q>>u>>v>>t;
    for(int i=1;i<=n;i++) cin>>aa[i];
	sort(aa+1,aa+n+1,cmp);
	for(int i=1;i<=n;i++)
	  a.push(aa[i]);
	for(int i=1;i<=m;i++)
	{
		int maxn=-2147483647,f;
		if(!a.empty())if(a.front()>maxn)maxn=a.front(),f=1;
		if(!b.empty())if(b.front()>maxn)maxn=b.front(),f=2;
		if(!c.empty())if(c.front()>maxn)maxn=c.front(),f=3;
		if(f==1)a.pop();else if(f==2)b.pop();else if(f==3)c.pop();
		maxn+=(i-1)*q;x=maxn*u/v;y=maxn-x;
		if(!(i%t)) cout<<maxn<<" ";b.push(x-i*q);c.push(y-i*q);
	}
	cout<<endl;
	int p=1;
	while(p)
	{
		int maxn=-2147483647,f;
		if(a.empty()&&b.empty()&&c.empty())break;
		if(!a.empty())if(a.front()>maxn)maxn=a.front(),f=1;
	    if(!b.empty())if(b.front()>maxn)maxn=b.front(),f=2;
	    if(!c.empty())if(c.front()>maxn)maxn=c.front(),f=3;
		if(f==1)a.pop();if(f==2)b.pop();if(f==3)c.pop();
		if(p%t==0)
		  cout<<maxn+(m)*q<<" ";        
		p++;                              
	}
	return 0;                       
}