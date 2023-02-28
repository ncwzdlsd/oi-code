#include<bits/stdc++.h>
using namespace std;

int n,a[100005],ss[100005],f[200005],ans;
string s;

int main()
{
	cin>>n>>s;
	for(int i=0;i<s.size();i++)
		ss[i+1]=ss[i]+(s[i]=='0'?-1:1);
	for(int i=1;i<=n;i++)
	{
		if(!f[ss[i]+n]) f[ss[i]+n]=i;
		else ans=max(ans,i-f[ss[i]+n]);
		if(ss[i]==0) ans=max(ans,i);
	}
	cout<<ans;
	return 0;
}