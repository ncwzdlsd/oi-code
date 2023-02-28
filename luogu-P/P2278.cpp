#include <bits/stdc++.h>
using namespace std;

struct node
{
	int num,t1,t2,val;
}gg[1000005];

struct cmp
{
	bool operator () (node &a,node &b)
	{
		return a.val<b.val||a.val==b.val&&a.num>b.num;
	}
};

int i=0,rest=0,size=0,tt,cnt=1;
priority_queue<node,vector<node>,cmp> q;

int main()
{
	while(cin>>gg[i+1].num>>gg[i+1].t1>>gg[i+1].t2>>gg[i+1].val) ++i;
	rest=i,gg[i+1].t1=1e9;
	while(rest!=0)
	{
		if(size==0) q.push(gg[cnt]),tt=gg[cnt].t1,size++,cnt++;
		node tmp=q.top();q.pop();size--;
		int last=tt;
		tt=min(gg[cnt].t1,last+tmp.t2);
		if(tt==last+tmp.t2)  cout<<tmp.num<<" "<<tt<<endl,rest--;
		else tmp.t2-=tt-last,q.push(tmp),size++;
		if(tt==gg[cnt].t1) q.push(gg[cnt]),size++,cnt++;
	}
	return 0;
}