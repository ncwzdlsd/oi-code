#include <bits/stdc++.h>
using namespace std;

const int maxm=1e5+5;
struct node{int l,r;}a[maxm];

bool cmp(node a,node b){return a.r<b.r;}

int main()
{
	int N,M;cin>>N>>M;
	for(int i=1;i<=M;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+M+1,cmp);
	int mxr=1,ans=0;
	for(int i=1;i<=M;i++)
		if(a[i].l>=mxr) mxr=a[i].r,ans++;
	cout<<ans;
	return 0;
}