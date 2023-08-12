#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;cin>>N;
	long long ans=0;
	for(int i=1;i<=N;i++)
	{
		int p;cin>>p;
		if(p==1||p==2) ans+=18;
		else if(p==3||p==4) ans+=14;
		else ans+=10;
		if(i==N) ans+=p;
	}
	cout<<ans;
	return 0;
}