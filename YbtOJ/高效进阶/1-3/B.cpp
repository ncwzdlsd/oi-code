#include <bits/stdc++.h>
using namespace std;
#define int long long

// 二分答案，ss(i)统计到位置i有多少防具，如果ss((1<<31)-1)为偶数，那么没有破绽
// 否则二分查找点P，在P之前有偶数个防具，在P之后有奇数个防具

const int maxn=2e5+5;
int S[maxn],E[maxn],D[maxn],N;

// 不能数组存，会炸
int ss(int x)
{
	int ans=0;
	for(int i=1;i<=N;i++)
		if(S[i]<=x) ans+=(min(x,E[i])-S[i])/D[i]+1;
	return ans;
}

signed main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=1;i<=N;i++) cin>>S[i]>>E[i]>>D[i];
		if(ss((1<<31)-1)%2==0) {puts("There's no weakness.");continue;}
		int l=0,r=(1<<31)-1,out;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(ss(mid)%2) r=mid-1,out=mid;
			else l=mid+1;
		}
		cout<<out<<' '<<ss(out)-ss(out-1)<<endl;
	}
	return 0;
}