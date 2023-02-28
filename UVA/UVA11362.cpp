#include <bits/stdc++.h>
using namespace std;

string s[10005];

int main()
{
	int t;cin>>t;
	while(t--)
	{
		bool flag=0;
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>s[i];
		sort(s+1,s+n+1);//按照字典序排列
		for(int i=1;i<n;i++)
			if(s[i+1].find(s[i],0)==0) {flag=1;break;}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}