#include <bits/stdc++.h>
using namespace std;

const int maxn=133343;
int cnt[maxn],pos[maxn],qcnt,cntt,ans[maxn],sum,a[maxn];

struct node{int l,r,id,t;}q1[maxn],q2[maxn]/*原、新*/;

void add(int i)
{
	if(!cnt[i]) sum++;
	cnt[i]++;
}

void del(int i)
{
	cnt[i]--;
	if(!cnt[i]) sum--;
}

bool cmp(node a,node b)
{
	if(pos[a.l]!=pos[b.l]) return a.l<b.l;
	if(pos[a.r]!=pos[b.r]) return a.r<b.r;
	return a.t<b.t;
}

void upd(int x,int t)
{
	if(q1[x].l<=q2[t].l&&q2[t].l<=q1[x].r)
		del(a[q2[t].l]),add(q2[t].r);
	swap(a[q2[t].l],q2[t].r);
}

int main()
{
	int N,M;cin>>N>>M;
	int len=pow(N,0.6);
	for(int i=1;i<=N;i++) pos[i]=(i-1)/len+1;
	for(int i=1;i<=N;i++) cin>>a[i];
	for(int i=1;i<=M;i++)
	{
		char opt;
		int L,R;
		cin>>opt>>L>>R;
		if(opt=='Q')
			++qcnt,q1[qcnt].id=qcnt,q1[
			
			qcnt].l=L,q1[qcnt].r=R,q1[qcnt].t=cntt;
		else
			q2[++cntt].l=L,q2[cntt].r=R;
	}
	sort(q1+1,q1+qcnt+1,cmp);
	int ll=1,rr=0,tt=0;
	for(int i=1;i<=qcnt;i++)
	{
		while(ll>q1[i].l) add(a[--ll]);
		while(ll<q1[i].l) del(a[ll++]);
		while(rr<q1[i].l) add(a[rr++]);
		while(rr>q1[i].r) del(a[--rr]);
		while(tt<q1[i].t) upd(i,++cntt);
		while(tt>q1[i].t) upd(i,cntt--);
		ans[q1[i].id]=sum;
	}
	for(int i=1;i<=qcnt;i++) cout<<ans[i]<<endl;
	return 0;
}