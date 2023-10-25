#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int maxn=3e5+5,ba=131;
int a[maxn],s[maxn],top;
ull ha[maxn],ans;
map<ull,int> mp;

void solve(int l,int r)
{
	int mid=(l+r)/2;
	if(l>=r) return;
	solve(l,mid),solve(mid+1,r);
	mp.clear(),top=0,ha[0]=0;
	for(int i=mid+1;i<=r;i++) 
	{
		if(top&&s[top--]==a[i]) top--;
		else s[++top]=a[i],ha[top]=ha[top-1]*ba+a[i];
		mp[ha[top]]++;
	}
	top=0,ha[0]=0;
	for(int i=mid;i>=l;i--)
	{
		if(top&&s[top]==a[i]) top--;
		else s[++top]=a[i],ha[top]=ha[top-1]*ba+a[i];
		ans+=mp[ha[top]];
	}
}

int main()
{
	int T;cin>>T;
	while(T--)
	{
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		ans=0,solve(1,n),cout<<ans<<endl;
	}
	return 0;
}