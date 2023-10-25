#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5,lenn=410;
int len,h[maxn],a[maxn],l[maxn],r[maxn],id[maxn],num[maxn],v[lenn][lenn],cnt;

bool check(int x,int y)
{return (long long)h[x]*y<(long long)h[y]*x;}

int work(int *ver,int l,int r,int mx)
{
	if(!mx) return l;
	if(!check(mx,ver[r])) return 0;
	int mid=0,ans=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mx,ver[mid])) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}

void rebuild(int id)
{
	num[id]=0;
	int last=0;
	for(int i=l[id];i<=r[id];i++) if(h[i]) 
		if(!last||check(last,i)) last=v[id][++num[id]]=i;
}
//你是我的答案(=v=)

int query()
{
	int tot=0,pos,mx=0;
	for(int i=1;i<=cnt;i++)
		if(num[i])
		{
			pos=work(v[i],1,num[i],mx);
			if(pos) tot+=num[i]-pos+1,mx=v[i][num[i]];
		}
	return tot;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N,M;cin>>N>>M;
	len=sqrt(N);
	cnt=N/len;
	if(N%len) cnt++;
	for(int i=1;i<=N;i++) id[i]=(i-1)/len+1;
	for(int i=1;i<=cnt;i++) l[i]=(i-1)*len+1,r[i]=i*len;
	r[cnt]=N;	
	for(int i=1;i<=M;i++)
	{
		int X,Y;cin>>X>>Y;
		h[X]=Y;
		rebuild(id[X]);
		cout<<query()<<endl;
	}
	return 0;
}