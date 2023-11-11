#include <bits/stdc++.h>
using namespace std;

int mp[1005][1005];

int main()
{
	int N;cin>>N;
	int ans=0;
	for(int i=1;i<=N;i++)
	{
		string a,b;cin>>a>>b;
		int t1=(a[0]-'A')*26+a[1],t2=(b[0]-'A')*26+b[1];
		if(t1!=t2) mp[t1][t2]++,ans+=mp[t2][t1];
	}
	cout<<ans;
	return 0;
}