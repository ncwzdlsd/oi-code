#include <bits/stdc++.h>
using namespace std;

const int maxn=200005;
int t,n,a[maxn],aa;
char s[maxn];
bool flagr,flagb,ans;

int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		a[aa=1]=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='W') a[++aa]=i;
		a[++aa]=n+1;
		ans=true;
		for(int i=1;i<aa;++i)
		{
			if(a[i+1]-a[i]<=1) continue;
			flagr=false;
			flagb=false;
			for(int j=a[i]+1;j<a[i+1];++j)
			{
				if(s[j]=='R') flagr=true;
				if(s[j]=='B') flagb=true;
			}
			if((!flagr)||(!flagb)) {ans=false;break;}
		}
		if(ans) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}