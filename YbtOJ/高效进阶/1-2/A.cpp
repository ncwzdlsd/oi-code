#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
int h[maxn];

int main()
{
	int N,A,B,ans=0;cin>>N>>A>>B;
	for(int i=1;i<=N;i++) cin>>h[i];
	sort(h+1,h+N+1);
	while(114514)
	{
		ans++;
		h[N]-=B;
		for(int i=N;i;--i)
		{
			if(h[i]<h[i-1]) swap(h[i],h[i-1]);
			else break;
		}
		if(h[N]-ans*A<=0) cout<<ans,exit(0);
	}
	return 0;
}