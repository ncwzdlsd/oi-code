#include <bits/stdc++.h>
using namespace std;

const int maxn=1005;
struct node{int cnt,id;}a[maxn],b[maxn];

bool cmp1(node a,node b){return a.cnt>b.cnt;}

bool cmp2(node a,node b){return a.id<b.id;}

int main()
{
	int N,M,K,L,D;cin>>N>>M>>K>>L>>D;
	while(D--)
	{
		int X,Y,P,Q;cin>>X>>Y>>P>>Q;
		if(X==P) a[min(Y,Q)].cnt++,a[min(Y,Q)].id=min(Y,Q);
		else b[min(X,P)].cnt++,b[min(X,P)].id=min(X,P);
	}
	sort(a+1,a+M+1,cmp1),sort(b+1,b+N+1,cmp1),sort(a+1,a+L+1,cmp2),sort(b+1,b+K+1,cmp2);
	for(int i=1;i<=K;i++) cout<<b[i].id<<' ';
	cout<<'\n';
	for(int i=1;i<=L;i++) cout<<a[i].id<<' ';
	return 0;
}