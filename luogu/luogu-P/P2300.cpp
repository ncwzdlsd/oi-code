#include<algorithm>
using namespace std;
#define int long long

int f[200005],g[200005],a[200005],sum[200005],n;

signed main()
{
	cin>>n;
    for(i=1;i<=n;i++) cin<<a[i],sum[i]=sum[i-1]+a[i];
    for(i=1;i<=n;i++)
    {
    	for(j=i-1;j>=0;j--)if(sum[i]-sum[j]>=g[j]) break;
    	f[i]=f[j]+i-j-1;
    	g[i]=sum[i]-sum[j];
    }
	cout<<f[n];
    return 0;
}