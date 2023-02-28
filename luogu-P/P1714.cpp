#include <cctype>
using namespace std;

const int maxn=500005;
int n,m,a[maxn],s[maxn],q[maxn],h=1,t=0,ans=-0x3f3f3f; 

int main()
{
	s[0]=0;
	cin>>n>>m;	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)	
	{
		while(h<=t&&s[q[t]]>=s[i]) t--;
		q[++t]=i;
		while(q[h]<i-m) h++;
		ans=max(ans,s[i]-s[q[h]]);
	}
	cout<<ans;
	return 0;
}