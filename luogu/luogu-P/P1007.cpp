#include <bits/stdc++.h>
using namespace std;

int a[5005];

int main()
{
	int L;cin>>L;
	int N;cin>>N;
	int ans1=0,ans2=0;
	for(int i=1;i<=N;i++)
	{
		int a;cin>>a;
		ans1=max(ans1,min(a,L-a+1)),ans2=max(ans2,max(a,L-a+1));
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}