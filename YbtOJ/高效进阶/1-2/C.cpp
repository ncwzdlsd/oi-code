#include <bits/stdc++.h>
using namespace std;

const int maxn=5e4+5;
int out[maxn],ans;

struct node
{
	int l,r,id;
	bool friend operator < (node a,node b)
	{
		return a.r>b.r;
	}
}a[maxn];//每头牛的编号、起始结束时间

priority_queue<node> q;//按照结束时间构造小顶堆，每次先选择最少吃完的

bool cmp(node a,node b)
{
	return a.l<b.l;
}//按左端点排序
// 如果当前牛开始吃草的时间比当前畜栏里的牛的最晚结束时间还晚，让它在这个畜栏吃就行
// 否则，为这个牛开一个新的畜栏

int main()
{
	int N;cin>>N;
	for(int i=1;i<=N;i++)
		cin>>a[i].l>>a[i].r,a[i].id=i;
	sort(a+1,a+N+1,cmp);
	for(int i=1;i<=N;i++)
	{
		if(q.empty()||q.top().r>=a[i].l) out[a[i].id]=q.size()+1;
		else out[a[i].id]=q.top().id,q.pop();
		q.push(a[i]);
	}
	cout<<q.size()<<endl;
	for(int i=1;i<=N;i++) cout<<out[i]<<endl;
	return 0;
}