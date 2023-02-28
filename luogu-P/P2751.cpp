#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
int N,M1,M2,ans[maxn];

struct node
{
	int id,t;
	friend bool operator < (node a,node b)
	{
		return a.t>b.t;
	}
}mach[maxn];

priority_queue<node> q1;
priority_queue<node> q2;

int main()
{
	cin>>N>>M1>>M2;
	int tmp;
	for(int i=1;i<=M1;i++) cin>>tmp,q1.push({tmp,tmp});
	for(int i=1;i<=M2;i++) cin>>tmp,q2.push({tmp,tmp});
	for(int i=1;i<=N;i++)
	{
		node now=q1.top();q1.pop();
		ans[i]+=now.t;
		q1.push({now.id,now.id+now.t});//把更新之后的时间压入
	}
	cout<<ans[N]<<' ';
	for(int i=N;i;i--)//注意因为建立的是小根堆，所以要倒着枚举
	{
		node now=q.top();q2.pop();
		ans[i]+=now.t;
		q2.push({now.id,now.id+now.t});
	}
	sort(ans+1,ans+N+1);
	cout<<ans[N];
	return 0;
}