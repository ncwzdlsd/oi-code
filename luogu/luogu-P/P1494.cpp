#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e4+5;
int sum,C[maxn],len,ans1[maxn],ans2[maxn],cnt[maxn],pos[maxn];

struct node{int id,l,r;}q[maxn];

bool cmp(node a,node b)
{
	if(pos[a.l]==pos[b.l]) return a.r<b.r;
	return a.l<b.l;
}

void add(int i){sum+=cnt[i],cnt[i]++;}

void del(int i){cnt[i]--,sum-=cnt[i];}

signed main()
{
	int N,M;cin>>N>>M;
	len=sqrt(N);
	for(int i=1;i<=N;i++) cin>>C[i];
	for(int i=1;i<=N;i++) pos[i]=(i-1)/len+1;
	for(int i=1;i<=M;i++) cin>>q[i].l>>q[i].r,q[i].id=i;
	sort(q+1,q+1+M,cmp);
	int l=1,r=0;
	for(int i=1;i<=M;i++)
	{
		if(q[i].l==q[i].r) {ans1[q[i].id]=0,ans2[q[i].id]=1;continue;}
		while(l>q[i].l) add(C[--l]);
		while(r<q[i].r) add(C[++r]);
		while(l<q[i].l) del(C[l++]);
		while(r>q[i].r) del(C[r--]);
		ans1[q[i].id]=sum,ans2[q[i].id]=(long long)(r-l+1)*(r-l)/2;
	}
	for(int i=1;i<=M;i++)
	{
		if(ans1[i]) {int g=__gcd(ans1[i],ans2[i]);ans1[i]/=g,ans2[i]/=g;}
		else ans2[i]=1;
		cout<<ans1[i]<<'/'<<ans2[i]<<endl;
	}
	return 0;
}