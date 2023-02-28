#include <algorithm>
using namespace std;

int p[105],v[105],n,w,f[300005],maxx,minn=0x3f3f3f,ans=0;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>p[i];
		minn=min(minn,v[i]);
		maxx=max(maxx,v[i]);
	}
	if(minn<=300)
	{
		for(int i=1;i<=n;i++)
			for(int j=w;j>=v[i];j--)
				f[j]=max(f[j],f[j-v[i]]+p[i]);
		cout<<f[w];
	}
	else
	{
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=w/maxx;i++) ans+=p[i];
		cout<<ans;
	}
	return 0;
}