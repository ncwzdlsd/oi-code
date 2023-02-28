#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator()(int x, int y)
	{
		return x > y;
	}
};

priority_queue<int,vector<int>,cmp>q;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int ans=0,n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		cin>>tmp,q.push(tmp);
	}
	for(int i=0;i<n-1;i++)
	{
		int t1,t2;
		t1=q.top();q.pop();
		t2=q.top();q.pop();
		ans+=t1+t2;
		q.push(t1+t2);
	}
	cout<<ans;
	return 0;
}